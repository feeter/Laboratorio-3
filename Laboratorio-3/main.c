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

typedef Nodo arbol;

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
    
    Nodo *root;

    root = NULL;
    
    /* Inserting nodes into tree */
    insert(&root, 9);
    insert(&root, 4);
    insert(&root, 15);
    insert(&root, 6);
    insert(&root, 12);
    insert(&root, 17);
    insert(&root, 2);

    
    print_inorder(root);
    printf("\n");
    
    return 0;
}
