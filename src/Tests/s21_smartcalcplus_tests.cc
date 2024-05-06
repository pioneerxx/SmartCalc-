#include <gtest/gtest.h>

#include "../Project/Model/CreditModel.h"
#include "../Project/Model/Model.h"

//----------------------------------------------------------------------------------------------//
s21::Model model;
s21::CreditModel creditmodel;

TEST(Calculation, everything) {
  bool errflag = 0, memoryflag = 0;
  char start_string[256] = {
      "(1+(1*(4*(5^4+(3*2*1.1/(3*sin(2*cos(1235.3)*2)))))))"};
  double result =
      model.SmartCalcPlus(start_string, ')', 0, &errflag, &memoryflag);
  EXPECT_EQ((int)result, 2769);
}

TEST(Calculation, addition_2) {
  char start_string[256] = {"21*cos(123)-100"};
  double check = 21 * cos(123) - 100;
  bool errflag = 0, memoryflag = 0;
  double result =
      model.SmartCalcPlus(start_string, '0', 0, &errflag, &memoryflag);
  ;
  EXPECT_DOUBLE_EQ(result, check);
}

TEST(Calculation, addition_3) {
  char start_string[256] = {"0+0"};
  bool errflag = 0, memoryflag = 0;
  double result =
      model.SmartCalcPlus(start_string, '0', 0, &errflag, &memoryflag);
  EXPECT_DOUBLE_EQ(result, 0.0);
}

TEST(Calculation, addition_4) {
  char start_string[256] = {"0+0"};
  bool errflag = 0, memoryflag = 0;
  double result =
      model.SmartCalcPlus(start_string, '0', 0, &errflag, &memoryflag);
  EXPECT_DOUBLE_EQ(result, 0.0);
}

TEST(Calculation, addition_5) {
  char start_string[256] = {"-100*(-5)"};
  bool errflag = 0, memoryflag = 0;
  double result =
      model.SmartCalcPlus(start_string, ')', 0, &errflag, &memoryflag);
  EXPECT_DOUBLE_EQ(result, -100 * -5);
}

//----------------------------------------------------------------------------------------------//

TEST(Calculation, subtraction_1) {
  char start_string[256] = {"10-5"};
  double check = 10 - 5;
  bool errflag = 0, memoryflag = 0;
  double result =
      model.SmartCalcPlus(start_string, '0', 0, &errflag, &memoryflag);
  EXPECT_DOUBLE_EQ(result, check);
}

TEST(Calculation, subtraction_2) {
  char start_string[256] = {"0-1000"};
  double check = 0 - 1000;
  bool errflag = 0, memoryflag = 0;
  double result =
      model.SmartCalcPlus(start_string, '0', 0, &errflag, &memoryflag);
  EXPECT_DOUBLE_EQ(result, check);
}

TEST(Calculation, subtraction_3) {
  char start_string[256] = {"32-32"};
  double check = 32 - 32;
  bool errflag = 0, memoryflag = 0;
  double result =
      model.SmartCalcPlus(start_string, '0', 0, &errflag, &memoryflag);
  EXPECT_DOUBLE_EQ(result, check);
}

TEST(Calculation, subtraction_4) {
  char start_string[256] = {"999-99-500-25-75-200-93-7-499"};
  double check = 999 - 99 - 500 - 25 - 75 - 200 - 93 - 7 - 499;
  bool errflag = 0, memoryflag = 0;
  double result =
      model.SmartCalcPlus(start_string, '0', 0, &errflag, &memoryflag);
  EXPECT_DOUBLE_EQ(result, check);
}

TEST(Calculation, subtraction_5) {
  char start_string[256] = {"999-99-500+25-75-200+93-7-499"};
  double check = 999 - 99 - 500 + 25 - 75 - 200 + 93 - 7 - 499;
  bool errflag = 0, memoryflag = 0;
  double result =
      model.SmartCalcPlus(start_string, '0', 0, &errflag, &memoryflag);
  EXPECT_DOUBLE_EQ(result, check);
}

//----------------------------------------------------------------------------------------------//

TEST(Calculation, multiplication_1) {
  char start_string[256] = {"10*5"};
  double check = 10 * 5;
  bool errflag = 0, memoryflag = 0;
  double result =
      model.SmartCalcPlus(start_string, '0', 0, &errflag, &memoryflag);
  EXPECT_DOUBLE_EQ(result, check);
}

TEST(Calculation, multiplication_2) {
  char start_string[256] = {"-0*1000"};
  double check = -0 * 1000;
  bool errflag = 0, memoryflag = 0;
  double result =
      model.SmartCalcPlus(start_string, '0', 0, &errflag, &memoryflag);
  EXPECT_DOUBLE_EQ(result, check);
}

TEST(Calculation, multiplication_3) {
  char start_string[256] = {"32*2"};
  double check = 32 * 2;
  bool errflag = 0, memoryflag = 0;
  double result =
      model.SmartCalcPlus(start_string, '0', 0, &errflag, &memoryflag);
  EXPECT_DOUBLE_EQ(result, check);
}

TEST(Calculation, multiplication_4) {
  char start_string[256] = {"2*2*2*8"};
  double check = 2 * 2 * 2 * 8;
  bool errflag = 0, memoryflag = 0;
  double result =
      model.SmartCalcPlus(start_string, '0', 0, &errflag, &memoryflag);
  EXPECT_DOUBLE_EQ(result, check);
}

TEST(Calculation, multiplication_5) {
  char start_string[256] = {"-7*6"};
  double check = -7 * 6;
  bool errflag = 0, memoryflag = 0;
  double result =
      model.SmartCalcPlus(start_string, '0', 0, &errflag, &memoryflag);
  EXPECT_DOUBLE_EQ(result, check);
}

//----------------------------------------------------------------------------------------------//

TEST(Calculation, division_1) {
  char start_string[256] = {"10/2"};
  double check = 10 / 2;
  bool errflag = 0, memoryflag = 0;
  double result =
      model.SmartCalcPlus(start_string, '0', 0, &errflag, &memoryflag);
  EXPECT_DOUBLE_EQ(result, check);
}

TEST(Calculation, division_2) {
  char start_string[256] = {"0/4567"};
  double check = 0 / 4567;
  bool errflag = 0, memoryflag = 0;
  double result =
      model.SmartCalcPlus(start_string, '0', 0, &errflag, &memoryflag);
  EXPECT_DOUBLE_EQ(result, check);
}

TEST(Calculation, division_3) {
  char start_string[256] = {"31/2"};
  bool errflag = 0, memoryflag = 0;
  double result =
      model.SmartCalcPlus(start_string, '0', 0, &errflag, &memoryflag);
  EXPECT_DOUBLE_EQ(result, 15.5);
}

TEST(Calculation, division_4) {
  char start_string[256] = {"100/2/2/5/5"};
  double check = 100 / 2 / 2 / 5 / 5;
  bool errflag = 0, memoryflag = 0;
  double result =
      model.SmartCalcPlus(start_string, '0', 0, &errflag, &memoryflag);
  EXPECT_DOUBLE_EQ(result, check);
}

TEST(Calculation, division_5) {
  char start_string[256] = {"-999/9"};
  double check = -999 / 9;
  bool errflag = 0, memoryflag = 0;
  double result =
      model.SmartCalcPlus(start_string, '0', 0, &errflag, &memoryflag);
  EXPECT_DOUBLE_EQ(result, check);
}

//----------------------------------------------------------------------------------------------//

TEST(Calculation, power_1) {
  char start_string[256] = {"10^2"};
  double check = pow(10, 2);
  bool errflag = 0, memoryflag = 0;
  double result =
      model.SmartCalcPlus(start_string, '0', 0, &errflag, &memoryflag);
  EXPECT_DOUBLE_EQ(result, check);
}

TEST(Calculation, power_2) {
  char start_string[256] = {"1^43"};
  bool errflag = 0, memoryflag = 0;
  double result =
      model.SmartCalcPlus(start_string, '0', 0, &errflag, &memoryflag);
  EXPECT_DOUBLE_EQ(result, 1.0);
}

TEST(Calculation, power_3) {
  char start_string[256] = {"3^2"};
  bool errflag = 0, memoryflag = 0;
  double result =
      model.SmartCalcPlus(start_string, '0', 0, &errflag, &memoryflag);
  EXPECT_DOUBLE_EQ(result, 9.0);
}

TEST(Calculation, power_4) {
  char start_string[256] = {"0^0"};
  bool errflag = 0, memoryflag = 0;
  double result =
      model.SmartCalcPlus(start_string, '0', 0, &errflag, &memoryflag);
  EXPECT_DOUBLE_EQ(result, 1.0);
}

TEST(Calculation, power_5) {
  char start_string[256] = {"-1^3"};
  bool errflag = 0, memoryflag = 0;
  double result =
      model.SmartCalcPlus(start_string, '0', 0, &errflag, &memoryflag);
  EXPECT_DOUBLE_EQ(result, -1.0);
}

//----------------------------------------------------------------------------------------------//

TEST(Calculation, cosine_1) {
  char start_string[256] = {"cos0-100"};
  bool errflag = 0, memoryflag = 0;
  double result =
      model.SmartCalcPlus(start_string, '0', 0, &errflag, &memoryflag);
  EXPECT_DOUBLE_EQ(result, cos(0) - 100);
}

TEST(Calculation, cosine_2) {
  char start_string[256] = {"cos(1)"};
  bool errflag = 0, memoryflag = 0;
  double result =
      model.SmartCalcPlus(start_string, '0', 0, &errflag, &memoryflag);
  EXPECT_DOUBLE_EQ(result, cos(1));
}

TEST(Calculation, cosine_3) {
  char start_string[256] = {"cos(-5)"};  // добавить проверку унарного минуса
  bool errflag = 0, memoryflag = 0;
  double result =
      model.SmartCalcPlus(start_string, '0', 0, &errflag, &memoryflag);
  EXPECT_DOUBLE_EQ(result, cos(-5));
}

TEST(Calculation, cosine_4) {
  char start_string[256] = {"cos(5)"};
  bool errflag = 0, memoryflag = 0;
  double result =
      model.SmartCalcPlus(start_string, '0', 0, &errflag, &memoryflag);
  EXPECT_DOUBLE_EQ(result, cos(5));
}

TEST(Calculation, sine_1) {
  char start_string[256] = {"sin(6)"};
  bool errflag = 0, memoryflag = 0;
  double result =
      model.SmartCalcPlus(start_string, '0', 0, &errflag, &memoryflag);
  EXPECT_DOUBLE_EQ(result, sin(6));
}

TEST(Calculation, sqrt_1) {
  char start_string[256] = {"sqrt(9)"};
  bool errflag = 0, memoryflag = 0;
  double result =
      model.SmartCalcPlus(start_string, '0', 0, &errflag, &memoryflag);
  EXPECT_DOUBLE_EQ(result, sqrt(9));
}

TEST(Calculation, log_1) {
  char start_string[256] = {"log(10)"};
  bool errflag = 0, memoryflag = 0;
  double result =
      model.SmartCalcPlus(start_string, '0', 0, &errflag, &memoryflag);
  EXPECT_DOUBLE_EQ(result, log10(10));
}

TEST(Calculation, ln_1) {
  char start_string[256] = {"ln(9)"};
  bool errflag = 0, memoryflag = 0;
  double result =
      model.SmartCalcPlus(start_string, '0', 0, &errflag, &memoryflag);
  EXPECT_DOUBLE_EQ(result, log(9));
}

TEST(Calculation, tan_1) {
  char start_string[256] = {"tan(9)"};
  bool errflag = 0, memoryflag = 0;
  double result =
      model.SmartCalcPlus(start_string, '0', 0, &errflag, &memoryflag);
  EXPECT_DOUBLE_EQ(result, tan(9));
}

TEST(Calculation, acos_1) {
  char start_string[256] = {"acos(0.5)"};
  bool errflag = 0, memoryflag = 0;
  double result =
      model.SmartCalcPlus(start_string, '0', 0, &errflag, &memoryflag);
  EXPECT_DOUBLE_EQ(result, acos(0.5));
}

TEST(Calculation, asin_1) {
  char start_string[256] = {"asin(0.5)"};
  bool errflag = 0, memoryflag = 0;
  double result =
      model.SmartCalcPlus(start_string, '0', 0, &errflag, &memoryflag);
  EXPECT_DOUBLE_EQ(result, asin(0.5));
}

TEST(Calculation, atan_1) {
  char start_string[256] = {"atan(0.5)"};
  bool errflag = 0, memoryflag = 0;
  double result =
      model.SmartCalcPlus(start_string, '0', 0, &errflag, &memoryflag);
  EXPECT_DOUBLE_EQ(result, atan(0.5));
}

TEST(Calculation, cosine_5) {
  char start_string[256] = {"cos0.30"};
  bool errflag = 0, memoryflag = 0;
  double result =
      model.SmartCalcPlus(start_string, '0', 0, &errflag, &memoryflag);
  EXPECT_DOUBLE_EQ(result, cos(0.30));
}

TEST(Calculation, mix_1) {
  char start_string[256] = {"(1+2)*3+5*4"};
  bool errflag = 0, memoryflag = 0;
  double result =
      model.SmartCalcPlus(start_string, '0', 0, &errflag, &memoryflag);
  EXPECT_DOUBLE_EQ(result, 29.0);
}

TEST(Calculation, mix_2) {
  char start_string[256] = {"(((1+2)))*3"};
  bool errflag = 0, memoryflag = 0;
  double result =
      model.SmartCalcPlus(start_string, '0', 0, &errflag, &memoryflag);
  EXPECT_DOUBLE_EQ(result, 9.0);
}

TEST(Calculation, mix_3) {
  char start_string[256] = {"(((1+2)))*3"};
  bool errflag = 0, memoryflag = 0;
  double result =
      model.SmartCalcPlus(start_string, '0', 0, &errflag, &memoryflag);
  EXPECT_DOUBLE_EQ(result, 9.0);
}

TEST(Calculation, mix_4) {
  char start_string[256] = {"(((1*2)))-3"};
  bool errflag = 0, memoryflag = 0;
  double result =
      model.SmartCalcPlus(start_string, '0', 0, &errflag, &memoryflag);
  EXPECT_DOUBLE_EQ(result, -1.0);
}

TEST(Calculation, mix_5) {
  char start_string[256] = {"1+2+3*(0-1)+(-1)"};
  bool errflag = 0, memoryflag = 0;
  double result =
      model.SmartCalcPlus(start_string, '0', 0, &errflag, &memoryflag);
  EXPECT_DOUBLE_EQ(result, -1.0);
}

TEST(Calculation, mix_6) {
  char start_string[256] = {"3+4*2/(1-5)^2"};
  bool errflag = 0, memoryflag = 0;
  double result =
      model.SmartCalcPlus(start_string, '0', 0, &errflag, &memoryflag);
  EXPECT_DOUBLE_EQ(result, 3.5);
}

TEST(Calculation, mix_7) {
  char start_string[256] = {"2+3^(2*1+1)"};
  double check = 2 + pow(3, 2 * 1 + 1);
  bool errflag = 0, memoryflag = 0;
  double result =
      model.SmartCalcPlus(start_string, '0', 0, &errflag, &memoryflag);
  EXPECT_DOUBLE_EQ(result, check);
}

TEST(Calculation, mix_8) {
  char start_string[256] = {"3+5*2/(6-4)^2"};
  bool errflag = 0, memoryflag = 0;
  double result =
      model.SmartCalcPlus(start_string, '0', 0, &errflag, &memoryflag);
  EXPECT_DOUBLE_EQ(result, 5.5);
}

TEST(Calculation, mix_9) {
  char start_string[256] = {"3+4*2/(2+0)^(3^1)*100"};
  bool errflag = 0, memoryflag = 0;
  double result =
      model.SmartCalcPlus(start_string, '0', 0, &errflag, &memoryflag);
  EXPECT_DOUBLE_EQ(result, 103.0);
}

TEST(Calculation, mix_10) {
  char start_string[256] = {"11+(7^2)"};
  bool errflag = 0, memoryflag = 0;
  double result =
      model.SmartCalcPlus(start_string, '0', 0, &errflag, &memoryflag);
  EXPECT_DOUBLE_EQ(result, 60.0);
}

TEST(Calculation, mix_11) {
  char start_string[256] = {"11+7^2"};
  bool errflag = 0, memoryflag = 0;
  double result =
      model.SmartCalcPlus(start_string, '0', 0, &errflag, &memoryflag);
  EXPECT_DOUBLE_EQ(result, 60.0);
}

TEST(Calculation, mix_12) {
  char start_string[256] = {"(0.432*54.2/4^2-(-8*4))*0.02"};
  bool errflag = 0, memoryflag = 0;
  double result =
      model.SmartCalcPlus(start_string, '0', 0, &errflag, &memoryflag);
  EXPECT_DOUBLE_EQ(result, 0.669268);
}

TEST(Calculation, empty) {
  char start_string[256] = {""};
  bool errflag = 0, memoryflag = 0;
  double result =
      model.SmartCalcPlus(start_string, '0', 0, &errflag, &memoryflag);
  EXPECT_EQ((int)result, 0);
}

// -----------------------------------------------
TEST(Calculation, mix_13) {
  char start_string[256] = {"11-(123124.0001+(42-32.327)-32)*423/432"};
  bool errflag = 0, memoryflag = 0;
  double result =
      model.SmartCalcPlus(start_string, '0', 0, &errflag, &memoryflag);
  EXPECT_EQ((int)result, -120526);
}

TEST(Calculation, mix_14) {
  char start_string[256] = {"32mod(32-30)"};
  bool errflag = 0, memoryflag = 0;
  double result =
      model.SmartCalcPlus(start_string, '0', 0, &errflag, &memoryflag);
  EXPECT_DOUBLE_EQ(result, 0.0);
}

TEST(Calculation, mix_15) {
  char start_string[256] = {"12-32*(2143-312*(4-5)-1.32/(83.2/3))"};
  bool errflag = 0, memoryflag = 0;
  double result =
      model.SmartCalcPlus(start_string, '0', 0, &errflag, &memoryflag);
  EXPECT_EQ((int)result, -78546);
}

TEST(Calculation, mix_16) {
  char start_string[256] = {"2^(3^2)-100"};
  bool errflag = 0, memoryflag = 0;
  double result =
      model.SmartCalcPlus(start_string, '0', 0, &errflag, &memoryflag);
  EXPECT_DOUBLE_EQ(result, 412.0);
}

TEST(Calculation, mix_17) {
  char start_string[256] = {"2^(3^2)+10"};
  bool errflag = 0, memoryflag = 0;
  double result =
      model.SmartCalcPlus(start_string, '0', 0, &errflag, &memoryflag);
  EXPECT_DOUBLE_EQ(result, 522.0);
}

TEST(Calculation, mix_18) {
  char start_string[256] = {"2+3^(2*1+1)"};
  bool errflag = 0, memoryflag = 0;
  double result =
      model.SmartCalcPlus(start_string, '0', 0, &errflag, &memoryflag);
  EXPECT_DOUBLE_EQ(result, 29.0);
}

TEST(Calculation, mix_19) {
  char start_string[256] = {"512/(2)^(3^2)*100+3"};
  bool errflag = 0, memoryflag = 0;
  double result =
      model.SmartCalcPlus(start_string, '0', 0, &errflag, &memoryflag);
  EXPECT_DOUBLE_EQ(result, 103.0);
}

//----------------------------------------------------------------------------------------------//

TEST(Credit, credit_annuity_1) {
  double balance_owed = 10000, term = 12., percent = 7.0;
  double firstpayment = 0;
  double mounthly_payment = 0;
  double overpayment = 0;
  double total_payment = 0;
  creditmodel.CreditCalc(balance_owed, term, percent, &mounthly_payment,
                         &overpayment, &total_payment, &firstpayment, 1, 1);
  EXPECT_EQ((int)mounthly_payment, 865);
  EXPECT_EQ((int)overpayment, 383);
  EXPECT_EQ((int)total_payment, 10383);
}

TEST(Credit, credit_annuity_2) {
  double balance_owed = 150000, term = 15., percent = 9.0;
  double firstpayment = 0;
  double mounthly_payment = 0;
  double overpayment = 0;
  double total_payment = 0;
  creditmodel.CreditCalc(balance_owed, term, percent, &mounthly_payment,
                         &overpayment, &total_payment, &firstpayment, 1, 1);
  EXPECT_EQ((int)mounthly_payment, 10610);
  EXPECT_EQ((int)overpayment, 9156);
  EXPECT_EQ((int)total_payment, 159156);
}

TEST(Credit, credit_annuity_3) {
  double balance_owed = 1500000, term = 18, percent = 6.0;
  double firstpayment = 0;
  double mounthly_payment = 0;
  double overpayment = 0;
  double total_payment = 0;
  creditmodel.CreditCalc(balance_owed, term, percent, &mounthly_payment,
                         &overpayment, &total_payment, &firstpayment, 1, 1);
  EXPECT_EQ((int)mounthly_payment, 87347);
  EXPECT_EQ((int)overpayment, 72256);
  EXPECT_EQ((int)total_payment, 1572256);
}

TEST(Credit, credit_diff_1) {
  double balance_owed = 10000, term = 12, percent = 7.0;
  double firstpayment = 0;
  double mounthly_payment = 0;
  double overpayment = 0;
  double total_payment = 0;
  creditmodel.CreditCalc(balance_owed, term, percent, &mounthly_payment,
                         &overpayment, &total_payment, &firstpayment, 0, 1);
  EXPECT_EQ((int)firstpayment, 891);
  EXPECT_EQ((int)mounthly_payment, 838);
  EXPECT_EQ((int)overpayment, 379);
  EXPECT_EQ((int)total_payment, 10379);
}

TEST(Credit, credit_diff_2) {
  double balance_owed = 150000, term = 15.0, percent = 9.0;
  double firstpayment = 0;
  double mounthly_payment = 0;
  double overpayment = 0;
  double total_payment = 0;
  creditmodel.CreditCalc(balance_owed, term, percent, &mounthly_payment,
                         &overpayment, &total_payment, &firstpayment, 0, 1);
  EXPECT_DOUBLE_EQ(firstpayment, 11125.0);
  EXPECT_DOUBLE_EQ(mounthly_payment, 10075.0);
  EXPECT_DOUBLE_EQ(overpayment, 9000.0);
  EXPECT_DOUBLE_EQ(total_payment, 159000.0);
}

TEST(Credit, credit_diff_3) {
  double balance_owed = 1500000, term = 18, percent = 6.0;
  double firstpayment = 0;
  double mounthly_payment = 0;
  double overpayment = 0;
  double total_payment = 0;
  creditmodel.CreditCalc(balance_owed, term, percent, &mounthly_payment,
                         &overpayment, &total_payment, &firstpayment, 0, 1);
  EXPECT_EQ((int)firstpayment, 90833);
  EXPECT_EQ((int)mounthly_payment, 83750);
  EXPECT_EQ((int)overpayment, 71250);
  EXPECT_EQ((int)total_payment, 1571250);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
