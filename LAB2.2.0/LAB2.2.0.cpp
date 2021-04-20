﻿#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define NMAX 100

struct stack 
{
	float elem[NMAX];
	int top;
};

void init(struct stack* stk) 
{
	stk->top = 0;
}

void push(struct stack* stk, float f) 
{
	if (stk->top < NMAX) 
	{
		stk->elem[stk->top] = f;
		stk->top++;
	}
	else
		printf("Стек полон, количество элементов: %d !\n", stk->top);
}

float pop(struct stack* stk) 
{
	float elem;
	if ((stk->top) > 0)
	{
		stk->top--;
		elem = stk->elem[stk->top];
		return elem;
	}
	else
	{
		printf("Стек пуст!\n");
		return 0;
	}
}

float stkTop(struct stack* stk) 
{
	if ((stk->top) > 0) 
	{
		return stk->elem[stk->top - 1];
	}
	else 
	{
		printf("Стек пуст!\n");
		return 0;
	}
}

int getcount(struct stack* stk) 
{
	return stk->top;
}

int isempty(struct stack* stk) 
{
	if (stk->top == 0)    return 1;
	else return 0;
}

void stkPrint(struct stack* stk) 
{
	int i;
	i = stk->top; // i - количество элементов в стеке
	if (isempty(stk) == 1) return; // стек пуст
	do 
	{
		i--;
		printf("%f\n", stk->elem[i]);
	} 
	while (i > 0);
}

int main() 
{
	setlocale(LC_ALL, "Russian");
	
	struct stack* stk;
	int i, n;
	float elem;
	stk = (struct stack*)malloc(sizeof(struct stack));
	init(stk);
	printf("Введите количество элементов в стеке: ");
	scanf_s("%d", &n);
	for (i = 0; i < n; i++) 
	{
		printf("Введите элемент %d:", i);
		scanf_s("%f", &elem);
		push(stk, elem);
	}
	printf("В стеке %d элементов\n\n", getcount(stk));
	stkPrint(stk);
	printf("Верхний элемент %f\n", stkTop(stk));
	do 
	{
		printf("Извлекаем элемент %f, ", pop(stk));
		printf("в стеке осталось %d элементов\n", getcount(stk));
	} 
	while (isempty(stk) == 0);
	getchar();
	return 0;
}