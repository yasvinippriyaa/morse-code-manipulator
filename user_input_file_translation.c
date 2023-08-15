#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//defining the structure of node

struct Node{
	char value;
	struct Node* left;
	struct Node* right;
}* root;

char morseCode[100], j=0;

//function to create a node

struct Node* createNode(char val){
	struct Node* temp = (struct Node*)malloc (sizeof(struct Node*));
	temp->value = val;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

//function to encode normal text to morse code

char* morseEncode(char x)
{
    switch (x) {
    case 'a':        return ".-";
    case 'b':        return "-...";
    case 'c':        return "-.-.";
    case 'd':        return "-..";
    case 'e':        return ".";
    case 'f':        return "..-.";
    case 'g':        return "--.";
    case 'h':        return "....";
    case 'i':        return "..";
    case 'j':        return ".---";
    case 'k':        return "-.-";
    case 'l':        return ".-..";
    case 'm':        return "--";
    case 'n':        return "-.";
    case 'o':        return "---";
    case 'p':        return ".--.";
    case 'q':        return "--.-";
    case 'r':        return ".-.";
    case 's':        return "...";
    case 't':        return "-";
    case 'u':        return "..-";
    case 'v':        return "...-";
    case 'w':        return ".--";
    case 'x':        return "-..-";
    case 'y':        return "-.--";
    case 'z':        return "--..";
    case '1':        return ".----";
    case '2':        return "..---";
    case '3':        return "...--";
    case '4':        return "....-";
    case '5':        return ".....";
    case '6':        return "-....";
    case '7':        return "--...";
    case '8':        return "---..";
    case '9':        return "----.";
    case '0':        return "-----";
    default:
        return " ";
        exit(0);
    }
}

int main(){ 
    
    //variable declarations
    
    FILE *fp, *op;
    char* morse;
    int i=0, choice;
	char x, filename[100];
	
	//constructing the tree
	
	root = (struct Node*)malloc(sizeof(struct Node*));
	root->value = '~';
	{
	root->left = createNode('E');
	root->right = createNode('T');
	struct Node* root_l = root->left;
	struct Node* root_r = root->right;
	root_l->left = createNode('I');
	root_l->right = createNode('A');
	root_r->left = createNode('N');
	root_r->right = createNode('M');
	struct Node* root_l_l = root->left->left;
	struct Node* root_l_r = root->left->right;
	struct Node* root_r_l = root->right->left;
	struct Node* root_r_r = root->right->right;
	root_l_l->left = createNode('S');
	root_l_l->right = createNode('U');
	root_l_r->left = createNode('R');
	root_l_r->right = createNode('W');

	root_r_l->left = createNode('D');
	root_r_l->right = createNode('K');
	root_r_r->left = createNode('G');
	root_r_r->right = createNode('O');

	struct Node* root_l_l_l = root_l_l->left;
	root_l_l_l->left = createNode('H');
	root_l_l_l->right = createNode('V');

	root_l_l->right->left = createNode('F');

	struct Node* root_l_l_l_l = root_l_l_l->left;
	root_l_l_l_l->left = createNode('5');
	root_l_l_l_l->right = createNode('4');

	root_l_l_l->right->right = createNode('3');
	root_l_l->right->right = createNode(' ');
	root_l_l->right->right->right = createNode('2');
	root_l_r->left->left = createNode('L');

	struct Node* root_l_r_r = root_l_r->right;

	root_l_r_r->left = createNode('P');
	root_l_r_r->right = createNode('J');

	root_l_r_r->right->right = createNode('1');

	root_r_l->left->left = createNode('B');
	root_r_l->left->right = createNode('X');

	root_r_l->left->left->left = createNode('6');

	root_r_l->right->left = createNode('C');
	root_r_l->right->right = createNode('4');

	root_r_r->left->left = createNode('Z');
	root_r_r->left->right = createNode('Q');

	root_r_r->left->left->left = createNode('7');
	struct Node* root_r_r_r = root_r_r->right;

	root_r_r_r->left = createNode(' ');
	root_r_r_r->right = createNode(' ');
	root_r_r_r->left->left = createNode('8');
	root_r_r_r->right->left = createNode('9');
	root_r_r_r->right->right = createNode('0');
}
	struct Node* temproot;
	
	//welcome screen and getting choice from user
	
	printf("\n\n\tW E L C O M E    T O    M O R S E    C O D E    M A N I P U L A T O R !\n");
	printf("\tA B O U T--\n");
	printf("\tThe Morse Code was designed to quickly transfer messages using a series of “dots (.)” and “dashes (-)”. Morse code was named after Samuel Morse, one of the inventors of the telegraph.\n");
	printf("\tThis application is designed to get alphanumeric input as Text or Morse Code and convert it to the other form, i.e, ENCODE or DECODE\n");
	printf("\tFor example, the Morse code of 'H' is '....' and that of 'O' is '---'\n");
	while(1){
	    printf("\n\tAvailable operations: 1.Encode a Text file 2.Decode a Morse file 0.EXIT PROGRAM\n\tEnter your choice: ");
	    scanf("%d", &choice);
	    switch(choice){
	        case 0: //EXIT
	        {
	            printf("\n\tThank you for using our service!!");
	            exit(1);
	        }
	        case 1: //ENCODE
	        {
	            //get name of file
	            printf("\n\tEnter filename of the Text file: ");
            	scanf("%s", filename);
            	fp = fopen(filename, "r");
            	op = fopen("encoded.txt", "w");
            	//print encoded content to new file
            	while(1){
            	    x = fgetc(fp);
            	    if(x==EOF) break;
            	    if(x==' ') fputc('\n', op);
            	    else{
            	        fprintf(op, "%s ", morseEncode(x));
	                }
	            }
            	fclose(op);
            	fclose(fp);
            	//print the encoded file
            	op = fopen("encoded.txt", "r");
            	printf("\tMorse Coded text in the file 'encoded.txt': \n\n\t");
            	while(1){
            	    x=fgetc(op);
            	    if(x==EOF) break;
            	    printf("%c", x);
            	    if(x=='\n') printf("\t");
            	}
            	fclose(op);
	        } break;
            case 2: //DECODE
            {
                //get name of file
                printf("\n\tEnter filename of the MorseCoded file: ");
            	scanf("%s", filename);
            	fp = fopen(filename, "r");
            	//simultaneously print content being translated
            	printf("\n\tTranslated text in \"translated.txt\": \n\n");
            	op = fopen("translated.txt", "w");
            	temproot=root;
            	while(1){
            	    if(x==EOF) break;
            	    if(x=='\n') {
            	        printf(" ");
            	        fputc(' ', op);
            	    }
            	    while(1){
            	        x = fgetc(fp);
            	        if(x == '.'){
            	            temproot = temproot->left;
            	        }
            	        else if(x== '-'){
            	            temproot = temproot->right;
            	        }
            	        else break;
            	    }
            	    printf("%c", temproot->value);
            	    fputc(temproot->value, op);
            	    temproot = root;
            	}
                fclose(fp);
                fclose(op);
            }
            break;
            default:
                printf("Invalid choice..Try again!");
                break;
        }
    }
}