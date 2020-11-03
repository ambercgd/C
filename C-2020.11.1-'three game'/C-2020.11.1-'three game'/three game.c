#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>//���������rand��Ӧ��ͷ�ļ�
#define MAX_ROW 3//���������е��к������ֵ��һ��Ҫע��궨�����д�淶��
#define MAX_COL 3
//��������Ϸ����˼·�߼�
//1.�����˵�
//2.�������̲��ҽ��г�ʼ��
//2.1.�������̵ĳ�ʼ������
//3.��ӡ����
//3.1.������ӡ���̺���
//(��ʽ��ʼ��Ϸ---��Ҫͨ�������������ʽ�Դﵽ���ӵ�Ч����
//4.�������
//4.1.����������Ӻ�������Ҫͨ����������������ʽʵ�֣�
//5.�ж�ʤ����ϵ
//5.1.�����ж�ʤ����ϵ����
//5.1.1.�����ж�ƽ������ĺ���
//6.����������ӣ������������������
//6.1.���ɵ���������Ӻ���
//7.�ж�ʤ����ϵ//��5һ��
//8.�ص�2����ִ��

//��ע�⣡��һ������£��������βεĸı䲢����Ӱ�쵽ʵ�Σ��β���ʵ�εĿ�������
//          ���ǵ�������Ϊ��������ʱ�������Ϊ���⣬�β�Ҳ����Ч��

//5.1.1.�����ж�ƽ������ĺ���
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
//2.1.�������̳�ʼ������
void init(char chessBoard[MAX_ROW][MAX_COL]){
	for (int row = 0; row < MAX_ROW; row++){
		for (int col = 0; col < MAX_COL; col++){
			chessBoard[MAX_ROW][MAX_COL] = ' ';//��ʼ��Ϊ�ո�
		}

	}
}
//3.1.������ӡ���̺���
void printChessBoard(char chessBoard[MAX_ROW][MAX_COL]){
	printf("+---+---+---+\n");
	for (int row = 0; row < MAX_ROW; row++){
		printf("| %c | %c | %c |\n", chessBoard[row][0],chessBoard[row][1], chessBoard[row][2]);
		printf("+---+---+---+\n");
	}
}
//4.1.����������Ӻ�������Ҫͨ����������������ʽʵ�֣�
void playerMove(char chessBoard[MAX_ROW][MAX_COL]){
	while (1){
		int row = 0;
		int col = 0;
		printf("����������Ҫ�����λ��(row col)��");
		scanf("%d %d", &row, &col);
		//�ж��������ֵ�Ƿ���ȷ
		if (row < 0 || row >= MAX_ROW || col < 0 || col >= MAX_COL){
			printf("�������λ�ò������ṩ�ķ�Χ��!\n");
		}
		//�ж�����Ƿ�����������ȷ��λ��
		if (chessBoard[row][col] != ' '){
			printf("�������λ����������!\n");
		}
		chessBoard[row][col] = 'x';
		break;
	}
}
// 5.1.�����ж�ʤ����ϵ����
//�ж����е����Ƿ�����
//���ȶ��巵��ֵ��������
//   ���ء�x����ʾ��һ�ʤ
//   ���ء�o����ʾ���Ի�ʤ
//   ���ء� ����ʾʤ��δ��
//   ���ء�q����ʾ���ƽ��
char iswin(char chessBoard[MAX_ROW][MAX_COL]){
	//�ж����е����Ƿ�����
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
	//�ж��Խ����Ƿ�����
	if ((chessBoard[0][0] != ' ') && (chessBoard[0][0] == chessBoard[1][1])
		&& (chessBoard[0][0] == chessBoard[2][2])){
		return chessBoard[0][0];
	}
	if ((chessBoard[0][2] != ' ') && (chessBoard[0][2] == chessBoard[1][1])
		&& (chessBoard[0][2] == chessBoard[2][0])){
		return chessBoard[0][2];
	}
	//�ж������Ƿ����ˣ���������δ�жϳ�ʤ������ƽ�֣���δ������˵��ʤ��δ��
	if (isFull(chessBoard)){
		return 'q';
	}
	return ' ';
}
//6.1.���ɵ���������Ӻ���
void computerMove(char chessBoard[MAX_ROW][MAX_COL]){
	while (1){
		int row = rand() % MAX_ROW;//rand������srand�������ʱ�䣬��������С��MAX_ROW�����ֵ
		int col = rand()% MAX_COL;//ͬ�ϣ���Ӧ��ʱ�亯����main������
		//ע���ֹ�����Ѿ��������ӵĵط�
		if (chessBoard[row][col] == ' '){
			continue;
		}
		chessBoard[row][col] = 'o';

		break;
	}
}

//1.�����˵�
int menu(){
	printf("*************************************************\n");
	printf("*************************************************\n");
	printf("**************��ӭ������������Ϸ*****************\n");
	printf("*************************************************\n");
	printf("****************1.��ʼ��Ϸ***********************\n");
	printf("****************0.������Ϸ***********************\n");
	printf("*************************************************\n");
	printf("*************************************************\n");
	printf("����������ѡ��");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}
void game(){
	//2.�������̲��ҽ��г�ʼ��
	char chessBoard[MAX_ROW][MAX_COL] = { 0 };
	init(chessBoard);//����2.1.��Ӧ�ĺ���
	char winner = ' ';
	while (1){
		//3.��ӡ����
		printChessBoard(chessBoard);
		//4.��ʼ��Ϸ
		//4.1.�������
		playerMove(chessBoard);
		//5.�ж�ʤ����ϵ
		winner = iswin(chessBoard);
		//ע�ⷵ��ֵ������������ʱ��Ҫ����ѭ��
		if (winner != ' '){
			break;
		}
		printChessBoard(chessBoard);
		//6.�����������
		computerMove(chessBoard);
		printChessBoard(chessBoard);
		//7.�ж�ʤ����ϵ
		winner = iswin(chessBoard);
		//ע�ⷵ��ֵ������������ʱ��Ҫ����ѭ��
		if (winner != ' '){
			break;
		}
	}
	    printChessBoard(chessBoard);
				if (winner == 'x'){
					printf("��ϲ������������ϷӮ����\n");
				}
				if (winner == '0'){
					printf("���ź��������ˣ�\n");
				}
				if (winner == 'q'){
					printf("��������ƽ������\n");
				}
			}

int main(){
	srand((unsigned int)time(0));//srand��rand�������ʱ�䣬�������ֵ
	while (1){
		int choice = menu();
		//�����û������0��1��Ϊ�������򣨰����������������
		if (choice == 1){
			game();
		}
		else if (choice == 0){
			printf("������Ϸ���ټ���\n");
		}
		else{
			printf("����������ʽ����������0��1��\n");
		}

	}

	system("pause");
	return 0;
}