//
//  main.c
//  Laboratorio-3
//
//  Created by Jose Ignacio Campos Padilla on 30-12-19.
//  Copyright © 2019 Jose Ignacio Campos Padilla. All rights reserved.
//
//
// Este laboratorio tiene como objetivo la elaboración de un programa que permita almacenar una colección
// de números en un árbol binario ordenado. Los numeros seran entregados en un archivo de texto plano llamado
// “numeros.in”, donde la primera línea indicará cuántos elementos a guardar vienen en el archivo y en las
// siguientes líneas se encontrarán los números, tal como se muestra en la figura 1 donde vienen 15 números.

#include <stdio.h>
#include <stdlib.h>

struct nodo {
    int dato;
    struct nodo* izq;
    struct nodo* der;
} typedef Nodo;

void insert(Nodo** tree, int val)
{
    Nodo* temp = NULL;
    if(!(*tree))
    {
        temp = (Nodo*) malloc(sizeof(Nodo));
        temp->izq = temp->der = NULL;
        temp->dato = val;
        *tree = temp;
        return;
    }

    if(val < (*tree)->dato)
    {
        insert(&(*tree)->izq, val);
    }
    else if(val > (*tree)->dato)
    {
        insert(&(*tree)->der, val);
    }

}

void print_inorder(Nodo* tree)
{
    if (tree)
    {
        print_inorder(tree->izq);
        printf("%d ",tree->dato);
        print_inorder(tree->der);
    }
}

int main(int argc, const char * argv[]) {
    
    FILE* f = fopen("/Users/josigna.cp/Documents/USACH/Materias/Semestre 2/ANÁLISIS DE ALGORITMOS Y ESTRUCTURA DE DATOS/Laboratorio 3/numeros.in","r");
    
    Nodo *root;
    root = NULL;
    
    int size;
    int num = 0;
    
    
    fscanf(f,"%d",&size);
    
    while(num < size)    //while loop with condition
    {
        /* insertando nodos */
        int dato = 0;
        fscanf(f,"%d",&dato);
        
        insert(&root, dato);
        
        num++;        //incremento
    }
    
    print_inorder(root);
    printf("\n");
    
    return 0;
}
