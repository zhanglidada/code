// 总感觉还有点问题

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

// 阿拉伯数字到中文大写数字的映射
string chineseDigits[] = {"零", "壹", "贰", "叁", "肆", "伍", "陆", "柒", "捌", "玖"};
// 中文大写单位
string chineseUnits[] = {"", "拾", "佰", "仟", "万", "拾", "佰", "仟", "亿"};

// 将整数部分转换为中文大写
string convertIntegerPart(int integerPart) {
    stringstream ss;
    ss << integerPart;
    string integerStr = ss.str();

    vector<string> result;
    int len = integerStr.length();

    for (int i = 0; i < len; ++i) {
        int digit = integerStr[i] - '0';
        if (digit!= 0) {
            result.push_back(chineseDigits[digit]);
            result.push_back(chineseUnits[len - i - 1]);
        } else {
            if (!result.empty() && result.back()!= "零") {
                result.push_back("零");
            }
        }
    }

    // 处理连续的零
    string finalResult;
    for (int i = 0; i < result.size(); ++i) {
        if (result[i] == "零" && i + 1 < result.size() && result[i + 1] == "零") {
            continue;
        }
        finalResult += result[i];
    }

    // 处理拾前面的零（按照题目要求去掉多余的零）
    if (finalResult.find("零拾")!= string::npos) {
        finalResult.erase(finalResult.find("零拾"), 2);
        if (!finalResult.empty() && finalResult[0]!= '零') {
            finalResult.insert(0, "零");
        }
    }

    return finalResult;
}

// 将小数部分转换为中文大写
string convertDecimalPart(int decimalPart) {
    stringstream ss;
    ss << decimalPart;
    string decimalStr = ss.str();

    string result;
    for (int i = 0; i < decimalStr.length(); ++i) {
        int digit = decimalStr[i] - '0';
        if (digit!= 0) {
            result += chineseDigits[digit];
            if (i == 0) {
                result += "角";
            } else if (i == 1) {
                result += "分";
            }
        } else {
            if (i == 0) {
                result += "零角";
            } else if (i == 1) {
                result += "零分";
            }
        }
    }

    if (result == "零角零分") {
        result = "";
    }

    return result;
}

// 主函数，进行金额转换
int main() {
    double amount;
    cout << "请输入一个金额（double数）: ";
    cin >> amount;

    int integerPart = static_cast<int>(amount);
    int decimalPart = static_cast<int>((amount - integerPart) * 100);

    string integerResult = convertIntegerPart(integerPart);
    string decimalResult = convertDecimalPart(decimalPart);

    string finalResult = "人民币";
    finalResult += integerResult;
    if (!decimalResult.empty()) {
        finalResult += "元";
        finalResult += decimalResult;
    } else {
        finalResult += "元整";
    }

    cout << finalResult << endl;

    return 0;
}