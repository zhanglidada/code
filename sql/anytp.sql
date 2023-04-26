CREATE OR REPLACE TYPE NColPipe AUTHID DEFINER AS OBJECT (

 l_parm VARCHAR2(10),    -- the parameter given to the table function
 rows_requested NUMBER,  -- the parameter given to the table function
 ret_type       ANYTYPE, -- the return type of the table function
 rows_returned  NUMBER,  -- the number of rows currently returned by the table function

 STATIC FUNCTION ODCITableDescribe(rtype      OUT NOCOPY ANYTYPE,
                                   p_parm     IN         VARCHAR2,
                                   p_rows_req IN         NUMBER := 2)
 RETURN NUMBER,

 STATIC FUNCTION ODCITablePrepare(sctx       OUT NOCOPY NColPipe,
                                  ti         IN         sys.ODCITabFuncInfo,
                                  p_parm     IN         VARCHAR2,
                                  p_rows_req IN         NUMBER := 2 )
 RETURN NUMBER,

 STATIC FUNCTION ODCITableStart(sctx       IN OUT NOCOPY NColPipe,
                                p_parm     IN            VARCHAR2,
                                p_rows_req IN            NUMBER := 2 )
 RETURN NUMBER,

 MEMBER FUNCTION ODCITableFetch(self  IN OUT NOCOPY NColPipe,
                                nrows IN            NUMBER,
                                outset   OUT NOCOPY ANYDATASET)
 RETURN NUMBER,

 MEMBER FUNCTION ODCITableClose(self IN NColPipe) RETURN NUMBER,

 STATIC FUNCTION show(p_parm     IN VARCHAR2,
                      p_rows_req IN NUMBER := 2)
 RETURN ANYDATASET PIPELINED USING NColPipe
 
 );


CREATE OR REPLACE TYPE BODY NColPipe AS

 STATIC FUNCTION ODCITableDescribe(rtype      OUT NOCOPY ANYTYPE,
                                   p_parm     IN         VARCHAR2,
                                   p_rows_req IN         NUMBER := 2 ) 
  RETURN NUMBER IS
  atyp anytype;
 BEGIN
   anytype.begincreate(dbms_types.typecode_object, atyp);
   IF p_parm = 'one' THEN
     atyp.addattr('one', dbms_types.typecode_varchar2, NULL, NULL, 10, NULL, NULL);
   ELSIF p_parm = 'two' THEN
     atyp.addattr('one', dbms_types.typecode_varchar2, NULL, NULL, 10, NULL, NULL);
     atyp.addattr('two', dbms_types.typecode_varchar2, NULL, NULL, 10, NULL, NULL);
   ELSE
     atyp.addattr(p_parm || '1', dbms_types.typecode_varchar2, NULL, NULL, 10, NULL, NULL);
     atyp.addattr(p_parm || '2', dbms_types.typecode_varchar2, NULL, NULL, 10, NULL, NULL);
     atyp.addattr(p_parm || '3', dbms_types.typecode_number, 10, 0, NULL, NULL, NULL);
   END IF;
   atyp.endcreate;
   anytype.begincreate(dbms_types.typecode_table, rtype);
   rtype.SetInfo(NULL, NULL, NULL, NULL, NULL, atyp, dbms_types.typecode_object, 0);
   rtype.endcreate();
   RETURN odciconst.success;
 EXCEPTION
   WHEN OTHERS THEN
     RETURN odciconst.error;
 END;


 STATIC FUNCTION ODCITablePrepare(sctx       OUT NOCOPY NColPipe,
                                  ti         IN         sys.ODCITabFuncInfo,
                                  p_parm     IN         VARCHAR2,
                                  p_rows_req IN         NUMBER := 2) RETURN NUMBER IS
  elem_typ sys.anytype;
  prec     PLS_INTEGER;
  scale    PLS_INTEGER;
  len      PLS_INTEGER;
  csid     PLS_INTEGER;
  csfrm    PLS_INTEGER;
  tc       PLS_INTEGER;
  aname    VARCHAR2(30);
 BEGIN
  tc := ti.RetType.GetAttrElemInfo(1, prec, scale, len, csid, csfrm, elem_typ, aname);
  sctx := NColPipe(p_parm, p_rows_req, elem_typ, 0);
  RETURN odciconst.success;
 END;


 STATIC FUNCTION ODCITableStart(sctx       IN OUT NOCOPY NColPipe,
                                p_parm     IN            VARCHAR2,
                                p_rows_req IN            NUMBER := 2) RETURN NUMBER IS
 BEGIN
   RETURN odciconst.success;
 END;


 MEMBER FUNCTION ODCITableFetch(self   IN OUT NOCOPY NColPipe,
                                nrows  IN            NUMBER,
                                outset    OUT NOCOPY ANYDATASET) RETURN NUMBER IS
 BEGIN
   anydataset.begincreate( dbms_types.typecode_object, self.ret_type, o utset );
   FOR i IN self.rows_returned + 1 .. self.rows_requested LOOP
     outset.addinstance;
     outset.piecewise();

     IF self.l_parm = 'one' THEN
       outset.setvarchar2(TO_CHAR(i));
     ELSIF self.l_parm = 'two' THEN
       outset.setvarchar2(TO_CHAR(i));
       outset.setvarchar2( 'row: ' || TO_CHAR(i));
     ELSE
       outset.setvarchar2( 'row: ' || TO_CHAR(i));
       outset.setvarchar2( 'row: ' || TO_CHAR(i));
       outset.setnumber( i );
     END IF;

     self.rows_returned := self.rows_returned + 1;
   END LOOP;
   outset.endcreate;
   RETURN odciconst.success;
 END;


 MEMBER FUNCTION ODCITableClose(self IN NColPipe) RETURN NUMBER IS
 BEGIN
   RETURN odciconst.success;
 END;

END;