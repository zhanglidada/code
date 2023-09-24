#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stdint.h>
#include <stddef.h>

#include "hashfunc.h"

/// the initial size of hash table
#ifndef HT_INITIAL_SIZE
#define HT_INITIAL_SIZE 64
#endif  // HT_INIT_SIZE

typedef struct hash_entry_struct hash_entry_t;
// The hash entry struct. Acts as a node in a linked list.
struct hash_entry_struct {
    void*               key;  // key

    void*               value;  // value

    size_t              key_size;  // key size in bytes

    size_t              value_size;  // value size in bytes

    /// This is used for collision resolution.
    hash_entry_t*       next;  // A pointer to the next hash entry in the chain (or NULL if none).
};


typedef struct hash_table_struct hash_table_t;
// primary hashtable struct
struct hash_table_struct {
    HashFunc*           hashfunc_x86_32;  // hash function for x86_32

    HashFunc*           hashfunc_x86_128;  // hash function for x86_128

    HashFunc*           hashfunc_x64_128;  // hash function for x64_128

    unsigned int        key_count;  // The number of keys in the hash table.

    unsigned int        array_size;  // The size of the internal array.

    hash_entry_t**      array;  // The internal hash table array.

    unsigned int        collisions;  // hash冲突个数

    int                 flags;  // Any flags that have been set. (See the ht_flags enum).

    /// The max load factor that is acceptable before an autoresize is triggered
    /// (where load_factor is the ratio of collisions to table size).
    double              max_load_factor;

    double              current_load_factor;  // The current load factor.
};

// Hashtable initialization flags (passed to ht_init)
typedef enum {

    // No options set
    HT_NONE = 0,

    // Constant length key, useful if your keys are going to be a fixed size.
    HT_KEY_CONST = 1,

    // Constant length value.
    HT_VALUE_CONST = 2,

    /// Don't automatically resize hashtable when the load factor
    /// goes above the trigger value
    HT_NO_AUTORESIZE = 4

} ht_flags;

/*---------------------------------- hashtable functions----------------------------------*/

/**
 * @brief Initializes the hash_table struct.
 * 
 * @param table A pointer to the hash table.
 * @param flags Options for the way the table behaves.
 * @param max_load_factor The ratio of collisions:table_size before an autoresize is triggered
 * 
 * for example: if max_load_factor = 0.1, the table will resize if the number
 * of collisions increases beyond 1/10th of the size of the table
 */
void ht_init(hash_table_t* table, ht_flags flags, double max_load_factor
#ifndef __WITH_MURMUR
        , HashFunc* for_x86_32, HashFunc* for_x86_128, HashFunc* for_x64_128
#endif //__WITH_MURMUR
);


/**
 * @brief Destroys the hash_table struct and frees all relevant memory.
 * 
 * @param table A pointer to the hash table.
 */
void ht_destroy(hash_table_t* table);


/**
 * @brief Inserts the {key: value} pair into the hash table, makes copies of both key and value.
 * 
 * @param table A pointer to the hash table.
 * @param key A pointer to the key.
 * @param key_size The size of the key in bytes.
 * @param value A pointer to the value.
 * @param value_size The size of the value in bytes.
 */
void ht_insert(hash_table_t* table, void* key, size_t key_size, void* value, size_t value_size);


/**
 * @brief Inserts an existing hash entry into the hash table.
 * 
 * @param table A pointer to the hash table.
 * @param entry A pointer to the hash entry.
 */
void ht_insert_he(hash_table_t* table, hash_entry_t* entry);


/**
 * @brief Returns a pointer to the value with the matching key,
 *        value_size is set to the size in bytes of the value
 * 
 * @param table A pointer to the hash table.
 * @param key A pointer to the key.
 * @param key_size The size of the key in bytes.
 * @param value_size A pointer to a size_t where the size of the return
 *                   value will be stored.
 * @return void* A pointer to the requested value. If the return value
 *               is NULL, the requested key-value pair was not in the table.
 */
void* ht_get(hash_table_t* table, void* key, size_t key_size, size_t* value_size);


/**
 * @brief Removes the entry corresponding to the specified key from the hash table.
 * 
 * @param table A pointer to the hash table.
 * @param key A pointer to the key.
 * @param key_size The size of the key in bytes.
 */ 
void ht_remove(hash_table_t* table, void* key, size_t key_size);


/**
 * @brief Used to see if the hash table contains a key-value pair.
 * 
 * @param table A pointer to the hash table.
 * @param key A pointer to the key.
 * @param key_size The size of the key in bytes.
 * @return int 1 if the key is in the table, 0 otherwise
 */
int ht_contains(hash_table_t* table, void* key, size_t key_size);


/**
 * @brief Returns the number of entries in the hash table.
 * 
 * @param table A pointer to the table.
 * @return unsigned int The number of entries in the hash table.
 */
unsigned int ht_size(hash_table_t* table);


/**
 * @brief Returns an array of all the keys in the hash table.
 * 
 * @param table A pointer to the hash table.
 * @param key_count A pointer to an unsigned int that
 *                  will be set to the number of keys in the returned array.
 * @return void** A pointer to an array of keys.
 * 
 * TODO: Add a key_lengths return value as well?
 */
void** ht_keys(hash_table_t* table, unsigned int* key_count);


/**
 * @brief Removes all entries from the hash table.
 * 
 * @param table A pointer to the hash table.
 */
void ht_clear(hash_table_t* table);


/**
 * @brief Calulates the index in the hash table's internal array
 *        from the given key (used for debugging currently).
 * 
 * @param table A pointer to the hash table.
 * @param key A pointer to the key.
 * @param key_size The size of the key in bytes.
 * @return unsigned int : The index into the hash table's internal array.
 */
unsigned int ht_index(hash_table_t* table, void* key, size_t key_size);


/**
 * @brief Resizes the hash table's internal array. This operation is
 *        _expensive_, however it can make an overfull table run faster
 *        if the table is expanded. The table can also be shrunk to reduce
 *        memory usage.
 * 
 * @param table A pointer to the table.
 * @param new_size The desired size of the table.
 */
void ht_resize(hash_table_t* table, unsigned int new_size);


/**
 * @brief Sets the global security seed to be used in hash function.
 * 
 * @param seed The seed to use.
 */
void ht_set_seed(uint32_t seed);


/**
 * @brief Creates a new hash entry.
 * 
 * @param flags Hash table flags.
 * @param key A pointer to the key.
 * @param key_size The size of the key in bytes.
 * @param value A pointer to the value.
 * @param value_size The size of the value in bytes.
 * @return hash_entry* A pointer to the hash entry.
 */
hash_entry_t* he_create(int flags, void* key, size_t key_size, void* value, size_t value_size);


/**
 * @brief Destroys the hash entry and frees all associated memory.
 * 
 * @param flags The hash table flags.
 * @param entry A pointer to the hash entry.
 */
void he_destroy(int flags, hash_entry_t* entry);


/**
 * @brief Compare two hash entries.
 * 
 * @param e1 A pointer to the first entry.
 * @param e2 A pointer to the second entry.
 * @return int
 *            1 if both the keys and the values of e1 and e2 match, 
 *            0 otherwise.
 *            This is a "deep" compare, rather than just comparing pointers.
 */
int he_key_compare(hash_entry_t* e1, hash_entry_t* e2);


/**
 * @brief Sets the value on an existing hash entry.
 * 
 * @param flags The hashtable flags.
 * @param entry A pointer to the hash entry.
 * @param value A pointer to the new value.
 * @param value_size The size of the new value in bytes.
 */
int he_set_value(int flags, hash_entry_t* entry, void* value, size_t value_size);

#endif