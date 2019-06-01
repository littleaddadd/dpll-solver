#include "sudoku.h"
#include "head.h"
int sudokuData::num[9][9];

/**
 * 函数名称：easyRandom
 * 函数参数：int nums
 * 函数功能：随机一个简单数独
 * 返回值：void
 **/
void easyRandom(int nums)
{
    switch (nums)
    {
        case 0:
        {
            /* 007 000 306
             * 600 400 270
             * 052 016 080
             *
             * 000 107 038
             * 078 000 590
             * 260 805 000
             *
             * 020 580 160
             * 031 009 007
             * 806 000 400
             */
            sudokuData::num[0][2]=7;
            sudokuData::num[0][6]=3;
            sudokuData::num[0][8]=6;

            sudokuData::num[1][0]=6;
            sudokuData::num[1][3]=4;
            sudokuData::num[1][6]=2;
            sudokuData::num[1][7]=7;

            sudokuData::num[2][1]=5;
            sudokuData::num[2][2]=2;
            sudokuData::num[2][4]=1;
            sudokuData::num[2][5]=6;
            sudokuData::num[2][7]=8;

            sudokuData::num[3][3]=1;
            sudokuData::num[3][5]=7;
            sudokuData::num[3][7]=3;
            sudokuData::num[3][8]=8;

            sudokuData::num[4][1]=7;
            sudokuData::num[4][2]=8;
            sudokuData::num[4][6]=5;
            sudokuData::num[4][7]=9;

            sudokuData::num[5][0]=2;
            sudokuData::num[5][1]=6;
            sudokuData::num[5][3]=8;
            sudokuData::num[5][5]=5;

            sudokuData::num[6][1]=2;
            sudokuData::num[6][3]=5;
            sudokuData::num[6][4]=8;
            sudokuData::num[6][6]=1;
            sudokuData::num[6][7]=6;

            sudokuData::num[7][1]=3;
            sudokuData::num[7][2]=1;
            sudokuData::num[7][5]=9;
            sudokuData::num[7][8]=7;

            sudokuData::num[8][0]=8;
            sudokuData::num[8][2]=6;
            sudokuData::num[8][6]=4;
            break;
        }
        case 1:
        {
            /*010 040 030
             *302 000 180
             *006 070 902
             *
             *080 095 000
             *000 308 000
             *000 460 050
             *
             *701 080 500
             *035 000 806
             *020 030 010
             */
            sudokuData::num[0][1]=1;
            sudokuData::num[0][4]=4;
            sudokuData::num[0][7]=3;

            sudokuData::num[1][0]=3;
            sudokuData::num[1][2]=2;
            sudokuData::num[1][6]=1;
            sudokuData::num[1][7]=8;

            sudokuData::num[2][2]=6;
            sudokuData::num[2][4]=7;
            sudokuData::num[2][6]=9;
            sudokuData::num[2][8]=2;

            sudokuData::num[3][1]=8;
            sudokuData::num[3][4]=9;
            sudokuData::num[3][5]=5;

            sudokuData::num[4][3]=3;
            sudokuData::num[4][5]=8;

            sudokuData::num[5][3]=4;
            sudokuData::num[5][4]=6;
            sudokuData::num[5][7]=5;

            sudokuData::num[6][0]=7;
            sudokuData::num[6][2]=1;
            sudokuData::num[6][4]=8;
            sudokuData::num[6][6]=5;

            sudokuData::num[7][1]=3;
            sudokuData::num[7][2]=5;
            sudokuData::num[7][6]=8;
            sudokuData::num[7][8]=6;

            sudokuData::num[8][1]=2;
            sudokuData::num[8][4]=3;
            sudokuData::num[8][7]=1;
            break;
        }
        case 2:
        {

            /*009 000 030
             *300 009 002
             *052 031 070
             *
             *004 250 000
             *290 000 051
             *000 013 200
             *
             *080 340 510
             *500 100 006
             *010 000 800
             */
            sudokuData::num[0][2]=9;
            sudokuData::num[0][7]=3;

            sudokuData::num[1][0]=3;
            sudokuData::num[1][5]=9;
            sudokuData::num[1][8]=2;

            sudokuData::num[2][1]=5;
            sudokuData::num[2][2]=2;
            sudokuData::num[2][4]=3;
            sudokuData::num[2][5]=1;
            sudokuData::num[2][7]=7;

            sudokuData::num[3][2]=4;
            sudokuData::num[3][3]=2;
            sudokuData::num[3][4]=5;

            sudokuData::num[4][0]=2;
            sudokuData::num[4][1]=9;
            sudokuData::num[4][7]=5;
            sudokuData::num[4][8]=1;

            sudokuData::num[5][4]=1;
            sudokuData::num[5][5]=3;
            sudokuData::num[5][6]=2;

            sudokuData::num[6][1]=8;
            sudokuData::num[6][3]=3;
            sudokuData::num[6][4]=4;
            sudokuData::num[6][6]=5;
            sudokuData::num[6][7]=1;

            sudokuData::num[7][0]=5;
            sudokuData::num[7][3]=1;
            sudokuData::num[7][8]=6;

            sudokuData::num[8][1]=1;
            sudokuData::num[8][6]=8;
            break;
        }
        case 3:
        {
            /*001 906 003
             *043 201 970
             *096 040 000
             *
             *809 000 700
             *472 508 691
             *005 000 204
             *
             *000 020 340
             *024 609 850
             *900 304 100
             */
            sudokuData::num[0][2]=1;
            sudokuData::num[0][3]=9;
            sudokuData::num[0][5]=6;
            sudokuData::num[0][8]=3;

            sudokuData::num[1][1]=4;
            sudokuData::num[1][2]=3;
            sudokuData::num[1][3]=2;
            sudokuData::num[1][5]=1;
            sudokuData::num[1][6]=9;
            sudokuData::num[1][7]=7;

            sudokuData::num[2][1]=9;
            sudokuData::num[2][2]=6;
            sudokuData::num[2][4]=4;

            sudokuData::num[3][0]=8;
            sudokuData::num[3][2]=9;
            sudokuData::num[3][6]=7;

            sudokuData::num[4][0]=4;
            sudokuData::num[4][1]=7;
            sudokuData::num[4][2]=2;
            sudokuData::num[4][3]=5;
            sudokuData::num[4][5]=8;
            sudokuData::num[4][6]=6;
            sudokuData::num[4][7]=9;
            sudokuData::num[4][8]=1;

            sudokuData::num[5][2]=5;
            sudokuData::num[5][6]=2;
            sudokuData::num[5][8]=4;

            sudokuData::num[6][4]=2;
            sudokuData::num[6][6]=3;
            sudokuData::num[6][7]=4;

            sudokuData::num[7][1]=2;
            sudokuData::num[7][2]=4;
            sudokuData::num[7][3]=6;
            sudokuData::num[7][5]=9;
            sudokuData::num[7][6]=8;
            sudokuData::num[7][7]=5;

            sudokuData::num[8][0]=9;
            sudokuData::num[8][3]=3;
            sudokuData::num[8][5]=4;
            sudokuData::num[8][6]=1;
            break;
        }
        case 4:
        {            
           /*600 000 000
            *039 400 602
            *100 370 008
            *
            *002 063 150
            *708 010 309
            *015 740 200
            *
            *800 054 003
            *901 008 760
            *000 000 004
            */
            sudokuData::num[0][0]=6;

            sudokuData::num[1][1]=3;
            sudokuData::num[1][2]=9;
            sudokuData::num[1][3]=4;
            sudokuData::num[1][6]=6;
            sudokuData::num[1][8]=2;

            sudokuData::num[2][0]=1;
            sudokuData::num[2][3]=3;
            sudokuData::num[2][4]=7;
            sudokuData::num[2][8]=8;

            sudokuData::num[3][2]=2;
            sudokuData::num[3][4]=6;
            sudokuData::num[3][5]=3;
            sudokuData::num[3][6]=1;
            sudokuData::num[3][7]=5;

            sudokuData::num[4][0]=7;
            sudokuData::num[4][2]=8;
            sudokuData::num[4][4]=1;
            sudokuData::num[4][6]=3;
            sudokuData::num[4][8]=9;

            sudokuData::num[5][1]=1;
            sudokuData::num[5][2]=5;
            sudokuData::num[5][3]=7;
            sudokuData::num[5][4]=4;
            sudokuData::num[5][6]=2;

            sudokuData::num[6][0]=8;
            sudokuData::num[6][4]=5;
            sudokuData::num[6][5]=4;
            sudokuData::num[6][8]=3;

            sudokuData::num[7][0]=9;
            sudokuData::num[7][2]=1;
            sudokuData::num[7][5]=8;
            sudokuData::num[7][6]=7;
            sudokuData::num[7][7]=6;

            sudokuData::num[8][8]=4;
            break;
        }
        case 5:
        {
           /*520 080 401
            *600 004 020
            *374 009 600
            *
            *097 810 000
            *000 203 000
            *000 097 810
            *
            *002 500 768
            *050 900 003
            *703 060 092
            */
            sudokuData::num[0][0]=5;
            sudokuData::num[0][1]=2;
            sudokuData::num[0][4]=8;
            sudokuData::num[0][6]=4;
            sudokuData::num[0][8]=1;

            sudokuData::num[1][0]=6;
            sudokuData::num[1][5]=4;
            sudokuData::num[1][7]=2;

            sudokuData::num[2][0]=3;
            sudokuData::num[2][1]=7;
            sudokuData::num[2][2]=4;
            sudokuData::num[2][5]=9;
            sudokuData::num[2][6]=6;

            sudokuData::num[3][1]=9;
            sudokuData::num[3][2]=7;
            sudokuData::num[3][3]=8;
            sudokuData::num[3][4]=1;

            sudokuData::num[4][3]=2;
            sudokuData::num[4][5]=3;

            sudokuData::num[5][4]=9;
            sudokuData::num[5][5]=7;
            sudokuData::num[5][6]=8;
            sudokuData::num[5][7]=1;

            sudokuData::num[6][2]=2;
            sudokuData::num[6][3]=5;
            sudokuData::num[6][6]=7;
            sudokuData::num[6][7]=6;
            sudokuData::num[6][8]=8;

            sudokuData::num[7][1]=5;
            sudokuData::num[7][3]=9;
            sudokuData::num[7][8]=3;

            sudokuData::num[8][0]=7;
            sudokuData::num[8][2]=3;
            sudokuData::num[8][4]=6;
            sudokuData::num[8][7]=9;
            sudokuData::num[8][8]=2;
            break;
        }
        case 6:
        {
           /*007 084 003
            *100 002 600
            *000 000 085
            *
            *540 006 800
            *003 705 900
            *001 900 024
            *
            *310 000 000
            *005 800 006
            *400 520 100
            */
            sudokuData::num[0][2]=7;
            sudokuData::num[0][4]=8;
            sudokuData::num[0][5]=4;
            sudokuData::num[0][8]=3;

            sudokuData::num[1][0]=1;
            sudokuData::num[1][5]=2;
            sudokuData::num[1][6]=6;

            sudokuData::num[2][7]=8;
            sudokuData::num[2][8]=5;

            sudokuData::num[3][0]=5;
            sudokuData::num[3][1]=4;
            sudokuData::num[3][5]=6;
            sudokuData::num[3][6]=8;

            sudokuData::num[4][2]=3;
            sudokuData::num[4][3]=7;
            sudokuData::num[4][5]=5;
            sudokuData::num[4][6]=9;

            sudokuData::num[5][2]=1;
            sudokuData::num[5][3]=9;
            sudokuData::num[5][7]=2;
            sudokuData::num[5][8]=4;

            sudokuData::num[6][0]=3;
            sudokuData::num[6][1]=1;

            sudokuData::num[7][2]=5;
            sudokuData::num[7][3]=8;
            sudokuData::num[7][8]=6;

            sudokuData::num[8][0]=4;
            sudokuData::num[8][3]=5;
            sudokuData::num[8][4]=2;
            sudokuData::num[8][6]=1;
            break;
        }
        case 7:
        {
           /*000 530 070
            *000 000 952
            *000 279 008
            *
            *000 024 700
            *031 000 480
            *007 910 000
            *
            *100 357 000
            *856 000 000
            *020 080 000
            */
            sudokuData::num[0][3]=5;
            sudokuData::num[0][4]=3;
            sudokuData::num[0][7]=7;

            sudokuData::num[1][6]=9;
            sudokuData::num[1][7]=5;
            sudokuData::num[1][8]=2;

            sudokuData::num[2][3]=2;
            sudokuData::num[2][4]=7;
            sudokuData::num[2][5]=9;
            sudokuData::num[2][8]=8;

            sudokuData::num[3][4]=2;
            sudokuData::num[3][5]=4;
            sudokuData::num[3][6]=7;

            sudokuData::num[4][1]=3;
            sudokuData::num[4][2]=1;
            sudokuData::num[4][6]=4;
            sudokuData::num[4][7]=8;

            sudokuData::num[5][2]=7;
            sudokuData::num[5][3]=9;
            sudokuData::num[5][4]=1;

            sudokuData::num[6][0]=1;
            sudokuData::num[6][3]=3;
            sudokuData::num[6][4]=5;
            sudokuData::num[6][5]=7;

            sudokuData::num[7][0]=8;
            sudokuData::num[7][1]=5;
            sudokuData::num[7][2]=6;

            sudokuData::num[8][1]=2;
            sudokuData::num[8][4]=8;
            break;
        }
        case 8:
        {
           /*080 200 000
            *905 000 006
            *042 000 019
            *
            *000 409 105
            *003 681 900
            *709 305 000
            *
            *890 000 570
            *500 000 308
            *000 002 090
            */
            sudokuData::num[0][1]=8;
            sudokuData::num[0][3]=2;

            sudokuData::num[1][0]=9;
            sudokuData::num[1][2]=5;
            sudokuData::num[1][8]=6;

            sudokuData::num[2][1]=4;
            sudokuData::num[2][2]=2;
            sudokuData::num[2][7]=1;
            sudokuData::num[2][8]=9;

            sudokuData::num[3][3]=4;
            sudokuData::num[3][5]=9;
            sudokuData::num[3][6]=1;
            sudokuData::num[3][8]=5;

            sudokuData::num[4][2]=3;
            sudokuData::num[4][3]=6;
            sudokuData::num[4][4]=8;
            sudokuData::num[4][5]=1;
            sudokuData::num[4][6]=9;

            sudokuData::num[5][0]=7;
            sudokuData::num[5][2]=9;
            sudokuData::num[5][3]=3;
            sudokuData::num[5][5]=5;

            sudokuData::num[6][0]=8;
            sudokuData::num[6][1]=9;
            sudokuData::num[6][6]=5;
            sudokuData::num[6][7]=7;

            sudokuData::num[7][0]=5;
            sudokuData::num[7][6]=3;
            sudokuData::num[7][8]=8;

            sudokuData::num[8][5]=2;
            sudokuData::num[8][7]=9;
            break;
        }
        default:
        {
           /*910 003 004
            *700 419 000
            *060 000 710
            *
            *400 097 000
            *003 000 200
            *000 520 003
            *
            *081 000 020
            *000 135 006
            *500 600 091
            */
            sudokuData::num[0][0]=9;
            sudokuData::num[0][1]=1;
            sudokuData::num[0][5]=3;
            sudokuData::num[0][8]=4;

            sudokuData::num[1][0]=7;
            sudokuData::num[1][3]=4;
            sudokuData::num[1][4]=1;
            sudokuData::num[1][5]=9;

            sudokuData::num[2][1]=6;
            sudokuData::num[2][6]=7;
            sudokuData::num[2][7]=1;

            sudokuData::num[3][0]=4;
            sudokuData::num[3][4]=9;
            sudokuData::num[3][5]=7;

            sudokuData::num[4][2]=3;
            sudokuData::num[4][6]=2;

            sudokuData::num[5][3]=5;
            sudokuData::num[5][4]=2;
            sudokuData::num[5][8]=3;

            sudokuData::num[6][1]=8;
            sudokuData::num[6][2]=1;
            sudokuData::num[6][7]=2;

            sudokuData::num[7][3]=1;
            sudokuData::num[7][4]=3;
            sudokuData::num[7][5]=5;
            sudokuData::num[7][8]=6;

            sudokuData::num[8][0]=5;
            sudokuData::num[8][3]=6;
            sudokuData::num[8][7]=9;
            sudokuData::num[8][8]=1;
            break;
        }
    }
}

/**
 * 函数名称：difficultRandom
 * 函数参数：int nums
 * 函数功能：随机一个困难棋盘
 * 返回值：void
 **/
void difficultRandom(int nums)
{

    switch (nums)
    {
        case 0:
        {
            /* 000 400 030
             * 004 007 102
             * 800 000 040
             *
             * 190 800 406
             * 000 902 000
             * 206 001 095
             *
             * 060 000 001
             * 409 100 300
             * 050 009 000
             */
            sudokuData::num[0][3]=4;
            sudokuData::num[0][7]=3;

            sudokuData::num[1][2]=4;
            sudokuData::num[1][5]=7;
            sudokuData::num[1][6]=1;
            sudokuData::num[1][8]=2;

            sudokuData::num[2][0]=8;
            sudokuData::num[2][7]=4;

            sudokuData::num[3][0]=1;
            sudokuData::num[3][1]=9;
            sudokuData::num[3][3]=8;
            sudokuData::num[3][6]=4;
            sudokuData::num[3][8]=6;

            sudokuData::num[4][3]=9;
            sudokuData::num[4][5]=2;

            sudokuData::num[5][0]=2;
            sudokuData::num[5][2]=6;
            sudokuData::num[5][5]=1;
            sudokuData::num[5][7]=9;
            sudokuData::num[5][8]=5;

            sudokuData::num[6][1]=6;
            sudokuData::num[6][8]=1;

            sudokuData::num[7][0]=4;
            sudokuData::num[7][2]=9;
            sudokuData::num[7][3]=1;
            sudokuData::num[7][6]=3;

            sudokuData::num[8][1]=5;
            sudokuData::num[8][5]=9;
            break;
        }
        case 1:
        {
            /*050 030 900
             *039 400 000
             *000 009 640
             *
             *060 008 400
             *500 000 008
             *001 900 020
             *
             *082 600 000
             *000 005 760
             *005 090 080
             */
            sudokuData::num[0][1]=5;
            sudokuData::num[0][4]=3;
            sudokuData::num[0][6]=9;

            sudokuData::num[1][1]=3;
            sudokuData::num[1][2]=9;
            sudokuData::num[1][3]=4;

            sudokuData::num[2][5]=9;
            sudokuData::num[2][6]=6;
            sudokuData::num[2][7]=4;

            sudokuData::num[3][1]=6;
            sudokuData::num[3][5]=8;
            sudokuData::num[3][6]=4;

            sudokuData::num[4][0]=5;
            sudokuData::num[4][8]=8;

            sudokuData::num[5][2]=1;
            sudokuData::num[5][3]=9;
            sudokuData::num[5][7]=2;

            sudokuData::num[6][1]=8;
            sudokuData::num[6][2]=2;
            sudokuData::num[6][3]=6;

            sudokuData::num[7][5]=5;
            sudokuData::num[7][6]=7;
            sudokuData::num[7][7]=6;

            sudokuData::num[8][2]=5;
            sudokuData::num[8][4]=9;
            sudokuData::num[8][7]=8;
            break;
        }
        case 2:
        {

            /*000 000 089
             *700 002 300
             *010 003 200
             *
             *800 036 702
             *000 905 000
             *901 280 003
             *
             *009 300 050
             *005 600 004
             *280 000 000
             */
            sudokuData::num[0][7]=8;
            sudokuData::num[0][8]=9;

            sudokuData::num[1][0]=7;
            sudokuData::num[1][5]=2;
            sudokuData::num[1][6]=3;

            sudokuData::num[2][1]=1;
            sudokuData::num[2][5]=3;
            sudokuData::num[2][6]=2;

            sudokuData::num[3][0]=8;
            sudokuData::num[3][4]=3;
            sudokuData::num[3][5]=6;
            sudokuData::num[3][6]=7;
            sudokuData::num[3][8]=2;

            sudokuData::num[4][3]=9;
            sudokuData::num[4][5]=5;

            sudokuData::num[5][0]=9;
            sudokuData::num[5][2]=1;
            sudokuData::num[5][3]=2;
            sudokuData::num[5][4]=8;
            sudokuData::num[5][8]=3;

            sudokuData::num[6][2]=9;
            sudokuData::num[6][3]=3;
            sudokuData::num[6][7]=5;

            sudokuData::num[7][2]=5;
            sudokuData::num[7][3]=6;
            sudokuData::num[7][8]=4;

            sudokuData::num[8][0]=2;
            sudokuData::num[8][1]=8;
            break;
        }
        case 3:
        {
            /*008 970 050
             *730 002 000
             *600 000 700
             *
             *400 300 008
             *300 090 007
             *800 005 001
             *
             *002 000 005
             *000 200 049
             *070 083 100
             */
            sudokuData::num[0][2]=8;
            sudokuData::num[0][3]=9;
            sudokuData::num[0][4]=7;
            sudokuData::num[0][7]=5;

            sudokuData::num[1][0]=7;
            sudokuData::num[1][1]=3;
            sudokuData::num[1][5]=2;

            sudokuData::num[2][0]=6;
            sudokuData::num[2][6]=7;

            sudokuData::num[3][0]=4;
            sudokuData::num[3][3]=3;
            sudokuData::num[3][8]=8;

            sudokuData::num[4][0]=3;
            sudokuData::num[4][4]=9;
            sudokuData::num[4][8]=7;

            sudokuData::num[5][0]=8;
            sudokuData::num[5][5]=5;
            sudokuData::num[5][8]=1;

            sudokuData::num[6][2]=2;
            sudokuData::num[6][8]=5;

            sudokuData::num[7][3]=2;
            sudokuData::num[7][7]=4;
            sudokuData::num[7][8]=9;

            sudokuData::num[8][1]=7;
            sudokuData::num[8][4]=8;
            sudokuData::num[8][5]=3;
            sudokuData::num[8][6]=1;
            break;
        }
        case 4:
        {
           /*859 100 002
            *600 000 000
            *001 028 030
            *
            *000 490 100
            *000 060 000
            *007 081 000
            *
            *030 710 800
            *000 000 006
            *900 006 754
            */
            sudokuData::num[0][0]=8;
            sudokuData::num[0][1]=5;
            sudokuData::num[0][2]=9;
            sudokuData::num[0][3]=1;
            sudokuData::num[0][8]=2;

            sudokuData::num[1][0]=6;

            sudokuData::num[2][2]=1;
            sudokuData::num[2][4]=2;
            sudokuData::num[2][5]=8;
            sudokuData::num[2][7]=3;

            sudokuData::num[3][3]=4;
            sudokuData::num[3][4]=9;
            sudokuData::num[3][6]=1;

            sudokuData::num[4][4]=6;

            sudokuData::num[5][2]=7;
            sudokuData::num[5][4]=8;
            sudokuData::num[5][5]=1;

            sudokuData::num[6][1]=3;
            sudokuData::num[6][3]=7;
            sudokuData::num[6][4]=1;
            sudokuData::num[6][6]=8;

            sudokuData::num[7][8]=6;

            sudokuData::num[8][0]=9;
            sudokuData::num[8][5]=6;
            sudokuData::num[8][6]=7;
            sudokuData::num[8][7]=5;
            sudokuData::num[8][8]=4;
            break;
        }
        case 5:
        {
           /*046 000 031
            *000 700 040
            *000 800 507
            *
            *300 005 620
            *000 060 000
            *061 400 003
            *
            *809 003 000
            *010 002 000
            *250 000 170
            */
            sudokuData::num[0][1]=4;
            sudokuData::num[0][2]=6;
            sudokuData::num[0][7]=3;
            sudokuData::num[0][8]=1;

            sudokuData::num[1][3]=7;
            sudokuData::num[1][7]=4;

            sudokuData::num[2][3]=8;
            sudokuData::num[2][6]=5;
            sudokuData::num[2][8]=7;

            sudokuData::num[3][0]=3;
            sudokuData::num[3][5]=5;
            sudokuData::num[3][6]=6;
            sudokuData::num[3][7]=2;

            sudokuData::num[4][4]=6;

            sudokuData::num[5][1]=6;
            sudokuData::num[5][2]=1;
            sudokuData::num[5][3]=4;
            sudokuData::num[5][8]=3;

            sudokuData::num[6][0]=8;
            sudokuData::num[6][2]=9;
            sudokuData::num[6][5]=3;

            sudokuData::num[7][1]=1;
            sudokuData::num[7][5]=2;

            sudokuData::num[8][0]=2;
            sudokuData::num[8][1]=5;
            sudokuData::num[8][6]=1;
            sudokuData::num[8][7]=7;
            break;
        }
        case 6:
        {
           /*000 008 090
            *000 400 250
            *003 009 001
            *
            *205 600 940
            *700 010 008
            *096 005 702
            *
            *300 100 600
            *029 003 000
            *070 200 000
            */
            sudokuData::num[0][5]=8;
            sudokuData::num[0][7]=9;

            sudokuData::num[1][3]=4;
            sudokuData::num[1][6]=2;
            sudokuData::num[1][7]=5;

            sudokuData::num[2][2]=3;
            sudokuData::num[2][5]=9;
            sudokuData::num[2][8]=1;

            sudokuData::num[3][0]=2;
            sudokuData::num[3][2]=5;
            sudokuData::num[3][3]=6;
            sudokuData::num[3][6]=9;
            sudokuData::num[3][7]=4;

            sudokuData::num[4][0]=7;
            sudokuData::num[4][4]=1;
            sudokuData::num[4][8]=8;

            sudokuData::num[5][1]=9;
            sudokuData::num[5][2]=6;
            sudokuData::num[5][5]=5;
            sudokuData::num[5][6]=7;
            sudokuData::num[5][8]=2;

            sudokuData::num[6][0]=3;
            sudokuData::num[6][3]=1;
            sudokuData::num[6][6]=6;

            sudokuData::num[7][1]=2;
            sudokuData::num[7][2]=9;
            sudokuData::num[7][5]=3;

            sudokuData::num[8][1]=7;
            sudokuData::num[8][3]=2;
            break;
        }
        case 7:
        {
           /*600 004 500
            *058 002 010
            *000 060 098
            *
            *200 009 004
            *800 241 006
            *500 600 001
            *
            *740 020 000
            *060 300 140
            *005 400 002
            */
            sudokuData::num[0][0]=6;
            sudokuData::num[0][5]=4;
            sudokuData::num[0][6]=5;

            sudokuData::num[1][1]=5;
            sudokuData::num[1][2]=8;
            sudokuData::num[1][5]=2;
            sudokuData::num[1][7]=1;

            sudokuData::num[2][4]=6;
            sudokuData::num[2][7]=9;
            sudokuData::num[2][8]=8;

            sudokuData::num[3][0]=2;
            sudokuData::num[3][5]=9;
            sudokuData::num[3][8]=4;

            sudokuData::num[4][0]=8;
            sudokuData::num[4][3]=2;
            sudokuData::num[4][4]=4;
            sudokuData::num[4][5]=1;
            sudokuData::num[4][8]=6;

            sudokuData::num[5][0]=5;
            sudokuData::num[5][3]=6;
            sudokuData::num[5][8]=1;

            sudokuData::num[6][0]=7;
            sudokuData::num[6][1]=4;
            sudokuData::num[6][4]=2;

            sudokuData::num[7][1]=6;
            sudokuData::num[7][3]=3;
            sudokuData::num[7][6]=1;
            sudokuData::num[7][7]=4;

            sudokuData::num[8][2]=5;
            sudokuData::num[8][3]=4;
            sudokuData::num[8][8]=2;
            break;
        }
        case 8:
        {
           /*000 050 921
            *003 740 800
            *800 600 000
            *
            *430 010 000
            *002 507 400
            *000 030 089
            *
            *000 006 008
            *008 095 200
            *165 080 000
            */
            sudokuData::num[0][4]=5;
            sudokuData::num[0][6]=9;
            sudokuData::num[0][7]=2;
            sudokuData::num[0][8]=1;

            sudokuData::num[1][2]=3;
            sudokuData::num[1][3]=7;
            sudokuData::num[1][4]=4;
            sudokuData::num[1][6]=8;

            sudokuData::num[2][0]=8;
            sudokuData::num[2][3]=6;

            sudokuData::num[3][0]=4;
            sudokuData::num[3][1]=3;
            sudokuData::num[3][4]=1;

            sudokuData::num[4][2]=2;
            sudokuData::num[4][3]=5;
            sudokuData::num[4][5]=7;
            sudokuData::num[4][6]=4;

            sudokuData::num[5][4]=3;
            sudokuData::num[5][7]=8;
            sudokuData::num[5][8]=9;

            sudokuData::num[6][5]=6;
            sudokuData::num[6][8]=8;

            sudokuData::num[7][2]=8;
            sudokuData::num[7][4]=9;
            sudokuData::num[7][5]=5;
            sudokuData::num[7][6]=2;

            sudokuData::num[8][0]=1;
            sudokuData::num[8][1]=6;
            sudokuData::num[8][2]=5;
            sudokuData::num[8][4]=8;
            break;
        }
        default:
        {

        /* 007 000 306
         * 600 400 270
         * 052 016 080
         *
         * 000 107 038
         * 078 000 590
         * 260 805 000
         *
         * 020 580 160
         * 031 009 007
         * 806 000 400
         */
        sudokuData::num[0][2]=7;
        sudokuData::num[0][6]=3;
        sudokuData::num[0][8]=6;

        sudokuData::num[1][0]=6;
        sudokuData::num[1][3]=4;
        sudokuData::num[1][6]=2;
        sudokuData::num[1][7]=7;

        sudokuData::num[2][1]=5;
        sudokuData::num[2][2]=2;
        sudokuData::num[2][4]=1;
        sudokuData::num[2][5]=6;
        sudokuData::num[2][7]=8;

        sudokuData::num[3][3]=1;
        sudokuData::num[3][5]=7;
        sudokuData::num[3][7]=3;
        sudokuData::num[3][8]=8;

        sudokuData::num[4][1]=7;
        sudokuData::num[4][2]=8;
        sudokuData::num[4][6]=5;
        sudokuData::num[4][7]=9;

        sudokuData::num[5][0]=2;
        sudokuData::num[5][1]=6;
        sudokuData::num[5][3]=8;
        sudokuData::num[5][5]=5;

        sudokuData::num[6][1]=2;
        sudokuData::num[6][3]=5;
        sudokuData::num[6][4]=8;
        sudokuData::num[6][6]=1;
        sudokuData::num[6][7]=6;

        sudokuData::num[7][1]=3;
        sudokuData::num[7][2]=1;
        sudokuData::num[7][5]=9;
        sudokuData::num[7][8]=7;

        sudokuData::num[8][0]=8;
        sudokuData::num[8][2]=6;
        sudokuData::num[8][6]=4;
        break;
        }
    }


}

/**
 * 函数名称：sudokutocnf
 * 函数参数：
 * 函数功能：将现成的数独棋盘打印成需要的cnf
 * 返回值：TRUE FALSE
 **/
status sudokutocnf()
{
    char filename[]="output";
    FILE *fp;
    if((fp=fopen(filename,"w"))==nullptr) return FALSE;
    int sudoku[9][9]={
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0},
            {0,0,9,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,8,0,0,0},
    };
    for (int i=0;i<9;i++) {
        for (int j=0;j<9;j++) {
            sudoku[i][j]=sudokuData::num[i][j];  //把gui读取的数组赋给soduko[9][9]
        }
    }

    int sudoku1[81];
    int feizeronum=0;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            sudoku1[i*9+j]=sudoku[i][j]; //转换为一维数组
            if(sudoku[i][j]>0)
                feizeronum++;   //统计非0值的个数
        }
    }
    int count=0;
    int row=1;
    int col=1;
    int inputnum;
    int clause[feizeronum];  //c99特性  变长数组
    int p=0;
    for (int k = 0; k < 81; ++k) {
        if (col==10)
        {
            row++;
            col=1;
        }
        if(sudoku1[k]>0) {
            inputnum = 81 * (row - 1) + 9 * (col - 1) + sudoku1[k]; //81*行+9*列+值
            //printf("%d\n",inputnum);
            clause[p]=inputnum;
            p++;
            count++;
        }
        col++;
    }
    int total_clauses=8829+count; //8829+统计的变元的个数
    fprintf(fp,"%c %s %d %d\n",'p',"cnf",729, total_clauses);
    for (int l = 0; l < feizeronum; ++l) {
        fprintf(fp,"%d %d\n",clause[l],0); //把为真的写进去
    }
    fclose(fp);
    return TRUE;
}

/**
 * 函数名称：at_least_once
 * 函数参数：
 * 函数功能：实现每个格子最少只有一个取值为真的转换
 * 返回值：TRUE FALSE
 **/
status at_least_once()
{
    char filename[]="output";
    FILE *fp;
    if((fp=fopen(filename,"a+"))==nullptr) return FALSE;
    int input_num;
    int a[9];
    for(int i=1;i<10;i++)
        for (int j = 1; j < 10; ++j) {
            for (int k = 1; k < 10; ++k) {
                input_num=81*(i-1) + 9*(j-1) + (k-1) + 1; //代表每一个格子的取值
                a[k-1]=input_num;
            }
            for (int l = 0; l <9 ; ++l) {
                fprintf(fp,"%d ",a[l]);
            }
            fprintf(fp,"%d\n",0);
        }
    fclose(fp);
    return TRUE;
    //81个式子
}

/**
 * 函数名称：row_at_most_once
 * 函数参数：
 * 函数功能：一行最多出现一次一个值
 * 返回值：TRUE FALSE
 **/
status row_at_most_once()
{
    char filename[]="output";
    FILE *fp;
    if((fp=fopen(filename,"a+"))==nullptr) return FALSE;
    int first_num;
    int second_num;
    for (int i = 1; i < 10; ++i) {
        for (int k = 1; k < 10; ++k) { //k表示的就是值
            for (int j = 1; j < 9; ++j) {
                for (int l = j+1; l < 10; ++l) { //从j开始往后的格子不允许出现等值的情况
                    first_num=81*(i-1) + 9*(j-1) + (k-1) + 1;
                    second_num=81*(i-1) + 9*(l-1) + (k-1) + 1;
                    fprintf(fp,"%d %d %d\n",-first_num,-second_num,0);
                }
            }
        }
    }
    fclose(fp);
    return TRUE;
}

/**
 * 函数名称：col_at_most_once
 * 函数参数：
 * 函数功能：一列最多出现一个值
 * 返回值：TRUE FALSE
 **/
status col_at_most_once()
{
    char filename[]="output";
    FILE *fp;
    if((fp=fopen(filename,"a+"))==nullptr) return FALSE;
    int first_num;
    int second_num;
    for (int j = 1; j < 10; ++j) {
        for (int k = 1; k < 10; ++k) { //表示值
            for (int i = 1; i < 9; ++i) { //列的rank数
                for (int l = i+1; l < 10; ++l) {
                    first_num=81*(i-1) + 9*(j-1) + (k-1) + 1;
                    second_num=81*(l-1) + 9*(j-1) + (k-1) + 1;
                    fprintf(fp,"%d %d %d\n",-first_num,-second_num,0);
                }
            }
        }
    }
    fclose(fp);
    return TRUE;
}

/**
 * 函数名称：three_square_atmost_once
 * 函数参数：
 * 函数功能：3*3的格子最多出现一次值
 * 返回值：TRUE FALSE
 **/
status three_square_atmost_once()
{
    char filename[]="output";
    FILE *fp;
    if((fp=fopen(filename,"a+"))==nullptr) return FALSE;
    int first_num;
    int second_num;

    for (int k = 1; k < 10; ++k) { //值
        for (int a = 0; a < 3; ++a) { //表示纵向第几个格子 0 1 2
            for (int b = 0; b < 3; ++b) { //表示横向第几个格子
                for (int u = 1; u < 4; ++u) { //表示在一个格子中纵向第几个位置 1 2 3
                    for (int v = 1; v < 3; ++v) { //表示在一个格子中横向第几个位置 1 2 3
                        for (int w = v+1; w < 4; ++w) { //首先保证3*3格子中的纵向不重复
                            first_num = 81 * ((3 * a + u) - 1) + 9 * ((3 * b + v) - 1) + (k - 1) + 1;
                            second_num = 81 * ((3 * a + u) - 1) + 9 * ((3 * b + w) - 1) + (k - 1) + 1;
                            fprintf(fp,"%d %d %d\n",-first_num, -second_num, 0);
                        }
                    }
                }
            }
        }
    }

    for (int k = 1; k < 10; ++k) {
        for (int a = 0; a < 3; ++a) {
            for (int b = 0; b < 3; ++b) {
                for (int u = 1; u < 3; ++u) {
                    for (int v = 1; v < 4; ++v) {
                        for (int w = u+1; w < 4; ++w) {
                            for (int t = 1; t < 4; ++t) {  //保证3*3格子中的横向不重复
                                first_num = 81*((3*a+u)-1) + 9*((3*b+v)-1) + (k-1) +1;
                                second_num = 81*((3*a+w)-1) + 9*((3*b+t) -1) + (k-1) + 1;
                                fprintf(fp,"%d %d %d\n",-first_num, -second_num, 0);
                            }
                        }
                    }
                }
            }
        }
    }
    fclose(fp);
    return TRUE;
}

/**
 * 函数名称：solvesudoku
 * 函数参数：cnfpoint *G
 * 函数功能：调用函数 解决数独 并在gui显示
 * 返回值：TRUE
 **/
status solvesudoku(cnfpoint *G)
{
    //81*(i)+9*j+k-1
    int judge;
    std::string filename="output";
    ReadCnfWithName(G,filename);
    InitAnswer(*G);
    judge=DPLL(G);

    if(judge==FALSE) return FALSE;

    int sudoku[81];
    for(int i=1,j=0;i<=answerlength;i++)
        if(answer[i].xnum>0) {
            sudoku[j] = answer[i].xnum*i;
            //printf("%d\n",answer[i].xnum*i);
            j++;
        }
    int answer[9][9];
    for (int i = 0; i < 81; ++i) {
        //printf("当前值%d\n",sudoku[i]);
        --sudoku[i];
        int x=sudoku[i]/81;
        sudoku[i]=sudoku[i]-81*x;
        int y=sudoku[i]/9;
        sudoku[i]=sudoku[i]-9*y;
        answer[x][y]=sudoku[i]+1;
        //printf("%d %d %d\n",x,y,sudoku[i]+1);
    }
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            //printf("%d ",answer[i][j]);
            sudokuData::num[i][j]=answer[i][j];
        }
        //printf("\n");
    }
    return TRUE;
}
