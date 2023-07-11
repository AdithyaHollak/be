#include<stdio.h>
#include<GL/gl.h>
#include<process.h>
#include<stdlib.h>
#include<Windows.h>
#include<GL/glu.h>
#include<GL/glut.h>

int maxi=0;
int flag=0;
int pos=0;
int mini=99999;


void renderscene()
{
    int i;

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.65,0.25,1.0);
    char c1[]="Press right button of mouse to get various options";
    glRasterPos2f(200.0,190.0);
    for(i=0; c1[i]!='\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,c1[i]);
    glFlush();
}

void d1()
{
    int i;

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,0.3,0.0);

    char c1[]="DOUBLY LINKED LIST";
    glRasterPos2f(580.0,300.0);
    for(i=0; c1[i]!='\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,c1[i]);

    glColor4f(0.0,0.5,0.5,0);
    char c2[]="Project done  by Adithya Holla K and Aditya Murugan";
    glRasterPos2f(200.0,250.0);
    for(i=0; c2[i]!='\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,c2[i]);

    glColor4f(0.75,0.5,0.0,0);
    char c3[]="Project done  Under the guidance of Mr Puneeth RP";
    glRasterPos2f(200.0,200.0);
    for(i=0; c3[i]!='\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,c3[i]);

    glColor4f(0.75,0.5,0.95,1);
    char c4[]="Please click on Enter Button To Enter The Next Page";
    glRasterPos2f(350.0,150.0);
    for(i=0; c4[i]!='\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,c4[i]);

    glFlush();

}

void displaycount(int i)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,0.3,0.0);
    char result[100];
    glColor4f(0.5,1,0.85,0);
    char t_nodes[100] = "No of nodes: ";
    sprintf(result, "%d", i);
    strcat(t_nodes, result);
    glRasterPos2f(800.0,200.0);
    for(int i=0; i<strlen(t_nodes); i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, t_nodes[i]);
    glFlush();
}
void d2()
{
    int i;

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,0.3,0.0);


    glColor4f(075,0.5,0.0,0);
    char c14[]="INTRODUCTION";
    glRasterPos2f(600.0,300.0);
    for(i=0; c14[i]!='\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,c14[i]);

    glColor4f(0.75,0.95,0.85,1);
    char c5[]="The aim of the network to show the working  the Doubly Linked list.";
    glRasterPos2f(50.0,250.0);
    for(i=0; c5[i]!='\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,c5[i]);

    char c6[]="Project is done basically by using the Open gl and CodeBlock.";
    glRasterPos2f(50.0,230.0);
    for(i=0; c6[i]!='\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,c6[i]);


    char c7[]="Here we can insert or delete the node by using various functions.";
    glRasterPos2f(50.0,210.0);
    for(i=0; c7[i]!='\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,c7[i]);

    char c8[]="Insert operations can be done by inserting Front ,Rear ,Left and Right.";
    glRasterPos2f(50.0,190.0);
    for(i=0; c8[i]!='\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,c8[i]);

    char c9[]="Also can delete the node by deleting Front,Rear and by specify Position.";
    glRasterPos2f(50.0,170.0);
    for(i=0; c9[i]!='\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,c9[i]);


    char c10[]="If the specify node is not there it shows node is not present.";
    glRasterPos2f(50.0,150.0);
    for(i=0; c10[i]!='\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,c10[i]);

    char c11[]="After deleting all the node the list display list is empty.";
    glRasterPos2f(50.0,130.0);
    for(i=0; c11[i]!='\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,c11[i]);


    glColor4f(0.75,0.5,0.95,1);
    char c12[]="Please click on caps A to go to next page.";
    glRasterPos2f(350.0,80.0);
    for(i=0; c12[i]!='\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,c12[i]);

    glFlush();
}

void mk(unsigned char key,int x,int y)

{

    if(key == 65)
    {
        renderscene();
    }
    else if(key == 13)
    {
        d2();
    }

}

void init()
{
    glClearColor(0.5,0.25,0.25,0.0);
    glColor3f(0.0f,0.0f,0.0f);
    glPointSize(0.8);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,2000.0,0.0,400.0);
}
struct node
{
    int info;
    struct node *rlink;
    struct node *llink;
};

typedef struct node *NODE;


static int count=0;
NODE head;
int h[100];
struct arr
{
    int p;
    int q;
} m[100];

NODE getnode()
{
    NODE temp;
    temp=(NODE)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("out of memory\n");
        exit(1);
    }
    return temp;
}
void disp()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,0.0,1.0);
    char c[]="List is Empty";
    glRasterPos2f(800.0,200.0);
    for(int i=0; c[i]!='\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,c[i]);

    glFlush();
}

NODE display(NODE head)
{
    if(flag==0)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1,1,1);

        NODE temp;
        int i=0,k,j=0;
        temp=head->rlink;
        if(temp==head)
        {
            printf(" list is empty\n");
            disp();
            return head;

        }
        printf("elements are\n");

        while(temp!=head)
        {
            for(k=0; k<count; k++)
            {
                GLfloat x1=100,x2=150,x3=350,x4=400,x5=500,x6=480,x7=20,x9=0;
                h[j]=temp->info;
                printf("%d\n",h[j]);
                glColor3f(0.0,0.0,0.0);
                char c[]="Info";
                glRasterPos2f(220.0,230.0);
                for(int a=0; c[a]!='\0'; a++)
                    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,c[a]);

                glColor3f(1,1,0);
                glBegin(GL_POLYGON);
                glVertex2i(x2+k*400,200);
                glVertex2i(x2+k*400,225);
                glVertex2i(x3+k*400,225);
                glVertex2i(x3+k*400,200);
                glEnd();
                glFlush();


                glColor3f(0.0,0.0,0.0);
                char r[]="rlink";
                glRasterPos2f(355.0,230.0);
                for(int b=0; r[b]!='\0'; b++)
                    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,r[b]);
                glColor3f(0.0,0.0,1.0);
                glBegin(GL_POLYGON);
                glVertex2i(x3+k*400,225);
                glVertex2i(x3+k*400,200);
                glVertex2i(x4+k*400,200);
                glVertex2i(x4+k*400,225);
                glEnd();
                glColor3f(0.0,0.0,0.0);
                char s[]="llink";
                glRasterPos2f(120.0,230.0);
                for(int d=0; s[d]!='\0'; d++)
                    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,s[d]);
                glColor3f(0.0,1.0,0.0);
                glBegin(GL_POLYGON);
                glVertex2i(x1+k*400,225);
                glVertex2i(x1+k*400,200);
                glVertex2i(x2+k*400,200);
                glVertex2i(x2+k*400,225);
                glEnd();
                glColor3f(0.0,1.0,0.0);
                glBegin(GL_LINES);
                glVertex2i(x1+k*400,207);
                glVertex2i(x9+k*400,207);
                glVertex2i(x9+k*400,207);
                glVertex2i(x7+k*400,202);
                glVertex2i(x9+k*400,207);
                glVertex2i(x7+k*400,210);
                glColor3f(0.0,0.0,1.0);
                glBegin(GL_LINES);
                glVertex2i(x4+k*400,215);
                glVertex2i(x5+k*400,215);
                glVertex2i(x5+k*400,215);
                glVertex2i(x6+k*400,210);
                glVertex2i(x5+k*400,215);
                glVertex2i(x6+k*400,219);
                glEnd();
                m[i].p=h[j]/10;
                m[i].q=h[j]%10;
                m[i].p=m[i].p+48;
                m[i].q=m[i].q+48;
                int x8=225;
                glColor3f(0.0,0.0,0.0);
                glRasterPos2i(x8+k*400,210);
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,m[i].p);
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,m[i].q);
                i++;
                j++;
                temp=temp->rlink;
                glFlush();
            }
        }
        return head;
    }
    else if(flag==1)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        NODE temp;
        int i=0,k,j=0;
        temp=head->rlink;
        if(temp==head)
        {
            printf(" list is empty\n");
            disp();
            return head;

        }
        printf("elements are\n");

        while(temp!=head)
        {
            for(k=0; k<count; k++)
            {
                GLfloat x1=100,x2=150,x3=350,x4=400,x5=500,x6=480,x7=20,x9=0;
                h[j]=temp->info;
                printf("%d\n",h[j]);
                glColor3f(0.0,0.0,0.0);
                char c[]="Info";
                glRasterPos2f(220.0,230.0);
                for(int a=0; c[a]!='\0'; a++)
                    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,c[a]);


                if(maxi==temp->info)
                    glColor3f(0,0.5,0.8);
                else
                    glColor3f(1,1,0);
                glBegin(GL_POLYGON);
                glVertex2i(x2+k*400,200);
                glVertex2i(x2+k*400,225);
                glVertex2i(x3+k*400,225);
                glVertex2i(x3+k*400,200);
                glEnd();
                glFlush();


                glColor3f(0.0,0.0,0.0);
                char r[]="rlink";
                glRasterPos2f(355.0,230.0);
                for(int b=0; r[b]!='\0'; b++)
                    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,r[b]);
                glColor3f(0.0,0.0,1.0);
                glBegin(GL_POLYGON);
                glVertex2i(x3+k*400,225);
                glVertex2i(x3+k*400,200);
                glVertex2i(x4+k*400,200);
                glVertex2i(x4+k*400,225);
                glEnd();
                glColor3f(0.0,0.0,0.0);
                char s[]="llink";
                glRasterPos2f(120.0,230.0);
                for(int d=0; s[d]!='\0'; d++)
                    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,s[d]);
                glColor3f(0.0,1.0,0.0);
                glBegin(GL_POLYGON);
                glVertex2i(x1+k*400,225);
                glVertex2i(x1+k*400,200);
                glVertex2i(x2+k*400,200);
                glVertex2i(x2+k*400,225);
                glEnd();
                glColor3f(0.0,1.0,0.0);
                glBegin(GL_LINES);
                glVertex2i(x1+k*400,207);
                glVertex2i(x9+k*400,207);
                glVertex2i(x9+k*400,207);
                glVertex2i(x7+k*400,202);
                glVertex2i(x9+k*400,207);
                glVertex2i(x7+k*400,210);
                glColor3f(0.0,0.0,1.0);
                glBegin(GL_LINES);
                glVertex2i(x4+k*400,215);
                glVertex2i(x5+k*400,215);
                glVertex2i(x5+k*400,215);
                glVertex2i(x6+k*400,210);
                glVertex2i(x5+k*400,215);
                glVertex2i(x6+k*400,219);
                glEnd();
                m[i].p=h[j]/10;
                m[i].q=h[j]%10;
                m[i].p=m[i].p+48;
                m[i].q=m[i].q+48;
                int x8=225;
                glColor3f(0.0,0.0,0.0);
                glRasterPos2i(x8+k*400,210);
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,m[i].p);
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,m[i].q);
                i++;
                j++;
                temp=temp->rlink;
                glFlush();
            }
        }
        return head;
    }
    else if(flag==2)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        NODE temp;
        int i=0,k,j=0;
        temp=head->rlink;
        if(temp==head)
        {
            printf(" list is empty\n");
            disp();
            return head;

        }
        printf("elements are\n");

        while(temp!=head)
        {
            for(k=0; k<count; k++)
            {
                GLfloat x1=100,x2=150,x3=350,x4=400,x5=500,x6=480,x7=20,x9=0;
                h[j]=temp->info;
                printf("%d\n",h[j]);
                glColor3f(0.0,0.0,0.0);
                char c[]="Info";
                glRasterPos2f(220.0,230.0);
                for(int a=0; c[a]!='\0'; a++)
                    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,c[a]);


                if(mini==temp->info)
                    glColor3f(0.5,0.5,0.5);
                else
                    glColor3f(1,1,0);
                glBegin(GL_POLYGON);
                glVertex2i(x2+k*400,200);
                glVertex2i(x2+k*400,225);
                glVertex2i(x3+k*400,225);
                glVertex2i(x3+k*400,200);
                glEnd();
                glFlush();


                glColor3f(0.0,0.0,0.0);
                char r[]="rlink";
                glRasterPos2f(355.0,230.0);
                for(int b=0; r[b]!='\0'; b++)
                    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,r[b]);
                glColor3f(0.0,0.0,1.0);
                glBegin(GL_POLYGON);
                glVertex2i(x3+k*400,225);
                glVertex2i(x3+k*400,200);
                glVertex2i(x4+k*400,200);
                glVertex2i(x4+k*400,225);
                glEnd();
                glColor3f(0.0,0.0,0.0);
                char s[]="llink";
                glRasterPos2f(120.0,230.0);
                for(int d=0; s[d]!='\0'; d++)
                    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,s[d]);
                glColor3f(0.0,1.0,0.0);
                glBegin(GL_POLYGON);
                glVertex2i(x1+k*400,225);
                glVertex2i(x1+k*400,200);
                glVertex2i(x2+k*400,200);
                glVertex2i(x2+k*400,225);
                glEnd();
                glColor3f(0.0,1.0,0.0);
                glBegin(GL_LINES);
                glVertex2i(x1+k*400,207);
                glVertex2i(x9+k*400,207);
                glVertex2i(x9+k*400,207);
                glVertex2i(x7+k*400,202);
                glVertex2i(x9+k*400,207);
                glVertex2i(x7+k*400,210);
                glColor3f(0.0,0.0,1.0);
                glBegin(GL_LINES);
                glVertex2i(x4+k*400,215);
                glVertex2i(x5+k*400,215);
                glVertex2i(x5+k*400,215);
                glVertex2i(x6+k*400,210);
                glVertex2i(x5+k*400,215);
                glVertex2i(x6+k*400,219);
                glEnd();
                m[i].p=h[j]/10;
                m[i].q=h[j]%10;
                m[i].p=m[i].p+48;
                m[i].q=m[i].q+48;
                int x8=225;
                glColor3f(0.0,0.0,0.0);
                glRasterPos2i(x8+k*400,210);
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,m[i].p);
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,m[i].q);
                i++;
                j++;
                temp=temp->rlink;
                glFlush();
            }

        }
        return head;
    }



}

NODE insertfront(NODE head,int item)
{
    NODE temp,cur;
    temp=getnode();
    temp->info=item;
    cur=head->rlink;
    head->rlink=temp;
    temp->llink=head;
    temp->rlink=cur;
    cur->llink=temp;
    return head;

}
NODE insertrear(NODE head,int item)
{
    NODE temp,cur;
    temp=getnode();
    temp->info=item;
    cur=head->llink;
    head->llink=temp;
    temp->rlink=head;
    temp->llink=cur;
    cur->rlink=temp;
    return head;
}
NODE insertleft(NODE head,int ele)
{
    int item;
    NODE temp,cur,pre;
    if(head->rlink==head)
    {
        printf("list is empty\n");
        count--;
        return head;
    }
    cur=head->rlink;
    while(cur!=head)
    {
        if(cur->info==ele)
            break;
        cur=cur->rlink;
    }
    if(cur==head)
    {
        printf("%d element not found\n",ele);
        count--;
        return head;
    }
    printf("enter element to be inserted\n");
    scanf("%d",&item);
    pre=cur->llink;
    temp=getnode();
    temp->info=item;
    temp->llink=pre;
    temp->rlink=cur;
    cur->llink=temp;
    pre->rlink=temp;
    return head;

}
NODE insertright(NODE head,int ele)
{
    int item;
    glClear(GL_COLOR_BUFFER_BIT);
    NODE temp,cur,next;
    if(head->rlink==head)
    {
        printf("list is empty\n");
        count--;
        return head;
    }
    cur=head->rlink;
    while(cur!=head)
    {
        if(cur->info==ele)
        {
            printf("enter element to be inserted\n");
            scanf("%d",&item);
            next=cur->rlink;
            temp=getnode();
            temp->info=item;
            temp->llink=cur;
            temp->rlink=next;
            cur->rlink=temp;
            next->llink=temp;
            return head;
        }
        cur=cur->rlink;
    }
    printf("%d element not found\n",ele);
    count--;
    return head;
}
NODE deletfront(NODE head)
{
    NODE cur,next;
    if(head->rlink==head)
    {
        printf("list is empty\n");
        count++;
        return head;
    }
    cur=head->rlink;
    next=cur->rlink;
    head->rlink=next;
    next->llink=head;
    printf("node to b deleted is %d\n",cur->info);
    free(cur);
    return head;
}
NODE deletrear(NODE head)
{
    NODE cur,prev;
    if(head->llink==head)
    {
        printf("list is empty\n");
        count++;
        return head;
    }
    cur=head->llink;
    prev=cur->llink;
    head->llink=prev;
    prev->rlink=head;
    printf("node to be deleted is %d\n",cur->info);
    free(cur);
    return head;
}

NODE del(NODE head,int ele)
{
    NODE cur,next,pre;
    glClear(GL_COLOR_BUFFER_BIT);
    if(head->rlink==head)
    {
        printf("list is empty\n");
        count++;
        return head;
    }
    cur=head->rlink;
    while(cur!=head)
    {
        if(cur->info==ele)
            break;
        cur=cur->rlink;
    }
    if(cur==head)
    {
        printf("%d element not found\n",ele);
        count++;
        return head;
    }
    pre=cur->llink;
    next=cur->rlink;
    printf("%d element found and deleted\n",ele);
    pre->rlink=next;
    next->llink=pre;
    free(cur);
    return head;

}

int maximum(NODE head)
{
    int i=0;
    NODE maxnode, temp;
    maxnode = head;
    temp = head->rlink;
    while (temp->info!= NULL)
    {
        if (temp->info > maxnode->info)
            maxnode = temp;
        temp = temp->rlink;
        i=i+1;
    }
    printf("Maximum node in the doubly linked list is  = %d \n", maxnode->info);
    maxi = maxnode->info;
    flag = 1;
    temp = display(head);

    return i;


}

int minimum(NODE head)
{
    flag=0;
    int i=0;
    NODE  temp;
    temp = head->rlink;
    while (temp->info!= NULL)
    {
        if (mini> temp->info)
            mini = temp->info;
        temp = temp->rlink;
        i=i+1;
    }
    printf("Minimum Node in the doubly linked list is = %d \n", mini);
    flag=2;
    temp=display(head);
    return i;
}

void countNodes(NODE head)
{
    int i = 0;
    NODE temp;
    temp=head->rlink;

    while (temp->info!= NULL)
    {
        i++;
        temp = temp->rlink;
    }
    char result[100];
    printf("No of nodes: %d\n",i);
    displaycount(i);
    glRasterPos2i(0,500);

    /* char t_nodes[100] = "No of nodes: ";
     sprintf(result, "%d", i);
     strcat(t_nodes, result);
     for(int i=0; i<strlen(t_nodes); i++)
         glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, t_nodes[i]);

     glFlush();*/



}

void top_menu(int option)
{
    int ele;
    switch(option)
    {
    case 1:

        printf("enter item to be inserted\n");
        scanf("%d",&ele);
        head=insertfront(head,ele);
        count++;
        display(head);
        break;
    case 2:
        printf("enter item to be inserted\n");
        scanf("%d",&ele);
        head=insertrear(head,ele);
        count++;
        display(head);
        break;
    case 3:
        printf("enter key to be searched\n");
        scanf("%d",&ele);
        head=insertleft(head,ele);
        count++;
        display(head);
        break;
    case 4:
        printf("enter key to be searched\n");
        scanf("%d",&ele);
        head=insertright(head,ele);
        count++;
        display(head);
        break;
    case 5:
        head=deletfront(head);
        count--;
        display(head);
        break;
    case 6:
        head=deletrear(head);
        count--;
        display(head);
        break;

    case 7:

        int n;
        printf("Enter no of nodes to delete");
        scanf("%d",&n);
        for(int a=0; a<n; a++)
        {
            printf("enter key\n");
            scanf("%d",&ele);
            count--;
            head=del(head,ele);

        }
        display(head);
        break;

    case 8:
        pos = maximum(head);
        flag=1;
        break;

    case 9:
        minimum(head);
        break;

    case 10:
        countNodes(head);

        break;

    case 11:
        exit(0);
    }
}
int  main(int argc,char**argv)
{
    head=getnode();
    head->rlink=head;
    head->llink=head;
    head->info=NULL;
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(620,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Doubly Linked List");
    glutCreateMenu(top_menu);
    glutAddMenuEntry("InsertFront",1);
    glutAddMenuEntry("InsertRear",2);
    glutAddMenuEntry("InsertLeft",3);
    glutAddMenuEntry("InsertRight",4);
    glutAddMenuEntry("DeleteFront",5);
    glutAddMenuEntry("DeleteRear",6);
    glutAddMenuEntry("DeleteSpecified",7);
    glutAddMenuEntry("Maximum Node",8);
    glutAddMenuEntry("Minimum Node",9);
    glutAddMenuEntry("Total Node",10);
    glutAddMenuEntry("Exit",11);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutDisplayFunc(d1);
    glutKeyboardFunc(mk);
    init();
    glutMainLoop();
    return 0;
}
