/****************************************************/
/*   AUTHOR      : Ahmed Bahaa Nasr                 */
/*   Description : Linked List Implementation       */
/*   DATE        : 20/3/2023                        */
/*   VERSION     : V01                              */
/****************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "../../../SWC/STD_TYPES.h"
typedef struct listnode
{
    u16 Data;
    struct listnode *Next;
}ListNode;
typedef struct linkedlist
{
  ListNode *Head;
  u16 size;
}List;
/* Functions Decleration */
void List_voidInitList(List *PL);
void List_voidInsertList(List *PL,u16 Copy_intPosition ,u16 Copy_intValue );
void List_voidInsertLast(List *PL,u16 Copy_intValue);
void List_voidReplaceList(List *PL,u16 Copy_intPosition ,u16 Copy_intValue);
void List_voidRetriveList(List *PL,u16 Copy_intPosition ,u16 *Value);
void List_voidDeleteList(List *PL,u16 Copy_intPosition ,u16 *Value);
void List_voidPrintList(List *PL);
void List_voidDestroyList(List *PL);
void List_voidTraverseList(List *PL,u16 *Copy_intValue);
u16 List_u16isEmpty(List *PL);
u16 List_u16isFull(List *PL);
u16 List_u16SizeList(List *PL);

u16 main()
{
    List L1 ;
    List *PL1 = &L1 ;
    u16 Value,size ;

 /* This Code To Check All Functions are working is correct */

    List_voidInitList(PL1);
    List_voidInsertList(PL1,0,10);
    List_voidInsertList(PL1,1,20);
    List_voidInsertList(PL1,2,30);
    List_voidInsertLast(PL1,35);
    List_voidInsertLast(PL1,50);

    printf("------------------------------\n");
    printf("-----------  START  ----------\n");
    printf("------------------------------\n");
    List_voidRetriveList(PL1,2,&Value);
    printf("The Retrived Value = %d\n", Value);
    printf("------------------------------\n");
    List_voidPrintList(PL1);
    size = List_u16SizeList(PL1);
    printf("The size of List is= %d\n", size);
    printf("------------------------------\n");
    List_voidReplaceList(PL1,2,40);
    List_voidRetriveList(PL1,2,&Value);
    printf("The Retrived Value that replaced = %d\n", Value);
    printf("------------------------------\n");
    List_voidPrintList(PL1);
    size = List_u16SizeList(PL1);
    printf("The size of List is= %d\n", size);
    printf("------------------------------\n");
    List_voidDeleteList(PL1,3,&Value);
    printf("The Deleted Value = %d\n", Value);
    printf("------------------------------\n");
    List_voidInsertList(PL1,2,30);
    List_voidPrintList(PL1);
    size = List_u16SizeList(PL1);
    printf("The size of List is= %d\n", size);
    printf("------------------------------\n");
    List_voidDestroyList(PL1);
    List_voidPrintList(PL1);
    size = List_u16SizeList(PL1);
    printf("The size of List is= %d\n", size);
    printf("------------------------------\n");
    printf("------------  END  -----------\n");
    printf("------------------------------\n");

 /* Now You Can Delete all of above then Use This Linked List Functions Implementation. */

    return 0;
}

/* Initilization Function Definition of Linked List  */
void List_voidInitList(List *PL)
{
    PL->Head = NULL ;
    PL->size = 0 ;
}
/* Insert Function Definition of Linked List */
void List_voidInsertList(List *PL,u16 Copy_intPosition ,u16 Copy_intValue )
{
    // Create New ListNode by dynamic memory allocation and Assign ListNode Pointer at (pn).
    ListNode *pn = (ListNode*)malloc(sizeof(ListNode));
    // Assign The Copy of Value at Data of the New Node.
    pn->Data = Copy_intValue ;
    // case 1 at insert first node on position 0.
    if ( Copy_intPosition == 0 )
    {
        pn->Next = PL->Head ;
        PL->Head = pn ;
    }
    // case 2 at insert any node on any position.
    else
    {
        // Create New Temporary Pointer.
        ListNode* Temp = PL->Head ;
        // Traverse loop to put Temp pointer at the node that have position-1 .
        for ( u16 i=0 ; i < Copy_intPosition-1 ; i++ )
        {
            Temp = Temp->Next ;
        }
        pn->Next = Temp->Next ;
        Temp->Next = pn ; 
    }
    // Increment Size of List Nodes.
    PL->size ++ ;
}
/* Insert Function Definition of Linked List insert at last position */
void List_voidInsertLast(List *PL,u16 Copy_intValue)
{
    // Create New ListNode by dynamic memory allocation and Assign ListNode Pointer at (pn).
    ListNode *pn =(ListNode*)malloc(sizeof(ListNode));
    // Assign The Copy of Value at Data of the New Node.
    pn->Data = Copy_intValue ;
    // Create New Temporary Pointer.
    ListNode* Temp = PL->Head ;
    // Traverse loop to put Temp pointer at the node that have Last position.
    for ( u16 i=0 ; i < PL->size-1 ; i++ )
    {
        Temp = Temp->Next ;
    }
    pn->Next = Temp->Next ;
    Temp->Next = pn ;
    // Increment Size of List Nodes.
    PL->size ++ ;
}
/* Replace Function Definition of Linked List to replace Data at any position */
void List_voidReplaceList(List *PL,u16 Copy_intPosition ,u16 Copy_intValue)
{
    // Create New Temporary Pointer.
    ListNode *Temp = PL->Head ;
    // Traverse loop to put Temp pointer at the node that have the position we need replace her data.
    for ( u16 i=0 ; i < Copy_intPosition ; i++ )
    {
        Temp = Temp->Next ;
    }
    // Assign the new data at the node.
    Temp->Data = Copy_intValue ;
}
/* Retrive Function Definition of Linked List to read data from any position */
void List_voidRetriveList(List *PL,u16 Copy_intPosition ,u16 *Value)
{
    ListNode *Temp = PL->Head ;
    for ( u16 i=0 ; i < Copy_intPosition ; i++ )
    {
        Temp = Temp->Next ;
    }
    *Value = Temp->Data ;
}
/* Delete Function Definition of Linked List to Delete node by her position */
void List_voidDeleteList(List *PL,u16 Copy_intPosition ,u16 *Value)
{
    ListNode *Temp , *pn ;
    // case 1 at we need delete the first node.
    if ( Copy_intPosition == 0 )
    {
        Temp = PL->Head->Next ;
        *Value = PL->Head->Data ;
        // free this Node from List.
        free(PL->Head);
        PL->Head = Temp ;
    }
    // case 2 at we need delete any node without first node.
    else
    {
        Temp = PL->Head ;
        for ( u16 i=0 ; i < Copy_intPosition-1 ; i++ )
        {
            Temp = Temp->Next ;
        }
        pn = Temp->Next ;
        Temp->Next = pn->Next ;
        *Value = pn->Data ;
        // free this Node from List.
        free(pn);
    }
    // Decrement Size of List Nodes.
    PL->size -- ;
}
/* Function Definition of Linked List to know Stack is Empty or Not */
u16 List_u16isEmpty(List *PL)
{
    return ( PL->Head == NULL );
}
/* Function Definition of Linked List to know List is Full or Not ( List can't be Fulled )*/
u16 List_u16isFull(List *PL)
{
    return 0 ;
}
/* Function Definition of Linked List to know Size of List */
u16 List_u16SizeList(List *PL)
{
    return ( PL->size );
}
/* Function Definition of Linked List to Destroy the List and her nodes */
void List_voidDestroyList(List *PL)
{
    ListNode *Temp = PL->Head ;
    while ( PL->Head != NULL )
    {
        Temp = Temp->Next ;
        free(PL->Head);
        PL->Head = Temp ;
    }
    // Decrement Size of List Nodes to be Zero Node.
    PL->size = 0 ; 
}

void List_voidTraverseList(List *PL,u16 *Copy_intValue)
{
    ListNode *Temp = PL->Head ;
    while ( Temp->Next != NULL )
    {
        *Copy_intValue = Temp->Data ;
        Temp = Temp->Next ;
    }
}
/* Function Definition of Linked List to Print All List Elements */
void List_voidPrintList(List *PL)
{
    // case 1 at list is not empty.
    if (!List_u16isEmpty(PL))
    {
        ListNode *Temp = PL->Head ;
        printf("All Element of List :\n");
         while ( Temp->Next != NULL )
         {
             printf("%d\n", Temp->Data );
             Temp = Temp->Next ;
         } 
         printf("%d\n", Temp->Data );
    }
    // case 2 at list is Empty.
    else
        printf("Sorry The List is Empty !!\n");
}



