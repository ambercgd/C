#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>//生成随机数rand对应的头文件
#define MAX_ROW 3//定义数组中的行和列最大值，一定要注意宏定义的书写规范！
#define MAX_COL 3
//三子棋游戏基本思路逻辑
//1.创建菜单
//2.创建棋盘并且进行初始化
//2.1.建立棋盘的初始化函数
//3.打印棋盘
//3.1.建立打印棋盘函数
//(正式开始游戏---主要通过输入坐标的形式以达到落子的效果）
//4.玩家落子
//4.1.建立玩家落子函数（主要通过玩家输入坐标的形式实现）
//5.判断胜负关系
//5.1.建立判断胜负关系函数
//5.1.1.建立判断平局情况的函数
//6.电脑随机落子（输入随机的坐标数）
//6.1.生成电脑随机落子函数
//7.判断胜负关系//和5一样
//8.回到2继续执行

//！注意！：一般情况下，函数中形参的改变并不会影响到实参（形参是实参的拷贝）；
//          但是当数组作为函数参数时，情况较为特殊，形参也能生效。

//5.1.1.建立判断平局情况的函数
int isFull(char chessBoard[MAX_ROW][MAX_COL]){
	for (int row = 0; row < MAX_ROW; row++){
		for (int col = 0; col < MAX_COL; col++){
			if (chessBoard[row][col] == ' '){
				return 0;
			}
		/*	return 1;*/
		}
	}
	return 1;
}
//2.1.建立棋盘初始化函数
void init(char chessBoard[MAX_ROW][MAX_COL]){
	for (int row = 0; row < MAX_ROW; row++){
		for (int col = 0; col < MAX_COL; col++){
			chessBoard[MAX_ROW][MAX_COL] = ' ';//初始化为空格
		}

	}
}
//3.1.建立打印棋盘函数
void printChessBoard(char chessBoard[MAX_ROW][MAX_COL]){
	printf("+---+---+---+\n");
	for (int row = 0; row < MAX_ROW; row++){
		printf("| %c | %c | %c |\n", chessBoard[row][0],chessBoard[row][1], chessBoard[row][2]);
		printf("+---+---+---+\n");
	}
}
//4.1.建立玩家落子函数（主要通过玩家输入坐标的形式实现）
void playerMove(char chessBoard[MAX_ROW][MAX_COL]){
	while (1){
		int row = 0;
		int col = 0;
		printf("请输入您想要落棋的位置(row col)：");
		scanf("%d %d", &row, &col);
		//判断玩家输入值是否正确
		if (row < 0 || row >= MAX_ROW || col < 0 || col >= MAX_COL){
			printf("您输入的位置不在所提供的范围内!\n");
		}
		//判断玩家是否将棋子落入正确的位置
		if (chessBoard[row][col] != ' '){
			printf("您输入的位置已有棋子!\n");
		}
		chessBoard[row][col] = 'x';
		break;
	}
}
// 5.1.建立判断胜负关系函数
//判定所有的列是否连线
//首先定义返回值所属代表：
//   返回‘x’表示玩家获胜
//   返回‘o’表示电脑获胜
//   返回‘ ’表示胜负未定
//   返回‘q’表示打成平局
char iswin(char chessBoard[MAX_ROW][MAX_COL]){
	//判定所有的行是否连线
	for (int row = 0; row < MAX_ROW; row++){
		if ((chessBoard[row][0] != ' ') && (chessBoard[row][0] == chessBoard[row][1])
			&& (chessBoard[row][0] == chessBoard[row][2]))
			return chessBoard[row][0];
	}
	for (int col = 0; col < MAX_COL; col++){
		if ((chessBoard[0][col] != ' ') && (chessBoard[0][col] == chessBoard[1][col])
			&& (chessBoard[0][col] == chessBoard[2][col]))
			return chessBoard[0][col];
	}
	//判定对角线是否连线
	if ((chessBoard[0][0] != ' ') && (chessBoard[0][0] == chessBoard[1][1])
		&& (chessBoard[0][0] == chessBoard[2][2])){
		return chessBoard[0][0];
	}
	if ((chessBoard[0][2] != ' ') && (chessBoard[0][2] == chessBoard[1][1])
		&& (chessBoard[0][2] == chessBoard[2][0])){
		return chessBoard[0][2];
	}
	//判断棋盘是否满了，若满了且未判断出胜负，则平局；若未满，则说明胜负未定
	if (isFull(chessBoard)){
		return 'q';
	}
	return ' ';
}
//6.1.生成电脑随机落子函数
void computerMove(char chessBoard[MAX_ROW][MAX_COL]){
	while (1){
		int row = rand() % MAX_ROW;//rand函数和srand函数结合时间，可以生成小于MAX_ROW的随机值
		int col = rand()% MAX_COL;//同上，对应的时间函数在main中引用
		//注意防止落入已经含有棋子的地方
		if (chessBoard[row][col] == ' '){
			continue;
		}
		chessBoard[row][col] = 'o';

		break;
	}
}

//1.创建菜单
int menu(){
	printf("*************************************************\n");
	printf("*************************************************\n");
	printf("**************欢迎来到三子棋游戏*****************\n");
	printf("*************************************************\n");
	printf("****************1.开始游戏***********************\n");
	printf("****************0.结束游戏***********************\n");
	printf("*************************************************\n");
	printf("*************************************************\n");
	printf("请输入您的选择：");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}
void game(){
	//2.创建棋盘并且进行初始化
	char chessBoard[MAX_ROW][MAX_COL] = { 0 };
	init(chessBoard);//引用2.1.对应的函数
	char winner = ' ';
	while (1){
		//3.打印棋盘
		printChessBoard(chessBoard);
		//4.开始游戏
		//4.1.玩家落子
		playerMove(chessBoard);
		//5.判定胜负关系
		winner = iswin(chessBoard);
		//注意返回值属于棋盘已满时需要跳出循环
		if (winner != ' '){
			break;
		}
		printChessBoard(chessBoard);
		//6.电脑随机落子
		computerMove(chessBoard);
		printChessBoard(chessBoard);
		//7.判定胜负关系
		winner = iswin(chessBoard);
		//注意返回值属于棋盘已满时需要跳出循环
		if (winner != ' '){
			break;
		}
	}
	    printChessBoard(chessBoard);
				if (winner == 'x'){
					printf("恭喜您，三子棋游戏赢啦！\n");
				}
				if (winner == '0'){
					printf("很遗憾，您输了！\n");
				}
				if (winner == 'q'){
					printf("哈哈哈，平局啦！\n");
				}
			}

int main(){
	srand((unsigned int)time(0));//srand和rand函数结合时间，生成随机值
	while (1){
		int choice = menu();
		//根据用户输入的0、1分为三个方向（包含输入错误的情况）
		if (choice == 1){
			game();
		}
		else if (choice == 0){
			printf("结束游戏，再见！\n");
		}
		else{
			printf("您的输入形式有误，请输入0或1！\n");
		}

	}

	system("pause");
	return 0;
}