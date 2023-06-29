/**
 * CSC A48 - Intro to Computer Science II
 * 
 * This is the program file where you will implement your solution for
 * assignment 1. Please make sure you read through this file carefully
 * and that you understand what is provided and what you need to complete.
 * 
 * You will need to have read the handout carefully. Parts where you have to 
 * implement functionality are clearly labeled TODO.
 * 
 * Be sure to test your work thoroughly, our testing will be extensive and will
 * check that your solution is *correct*, not only that it provides 
 * functionality.
 * 
 * Developed by Mustafa Quraish for CSCA48
 * (c) Mustafa Quraish
 */
#include "imgUtils.c"

// This lets the driver code override the image size if it needs to. Make sure 
// you don't hard-code these values anywhere!
#ifndef SIZEX
  #define SIZEX 512
  #define SIZEY 512
#endif 

/*---------------------------------------------------------------------------*/

/**
 * This struct contains one node of the linked list, which represents a single 
 * command to the Turtle. It's field should include:
 * 
 *  - cmd   : A char array of size 10 holding the command name
 * 
 *  - val   : An integer that stores a parameter for the command (like forward,
 *            backward and colour). 
 * 
 *  - next  : A pointer to a struct of the same type, this is used for the 
 *            linked list
 * 
 * TODO: Complete this struct definition
 ****/

typedef struct cmdnode {
	
	char cmd[10];
	int val;
	struct cmdnode *next;

} CmdNode;

/*---------------------------------------------------------------------------*/

CmdNode *newCmdNode(char cmd[10], int val) {
  /** 
   * This function allocates a new CmdNode struct and initializes it's values 
   * based on the input paramaters given. The next pointer is always 
   * initialized to NULL.
   * 
   * If the 'cmd' parameter is not a correct command, then print
   * "Invalid command.\n" and return NULL.
   * 
   * Note that we will always pass in a value here, even if the 
   * command doesn't need one. In this case, we can just ignore 
   * it. It saves us from having to make separate functions to 
   * deal with this.
   * 
   * TODO: Implement this function
   */
	
	if((strcmp(cmd, "forward") == 0) || (strcmp(cmd, "backward") == 0) || (strcmp(cmd, "penup") == 0) || 
		(strcmp(cmd, "pendown") == 0) || (strcmp(cmd, "colour") == 0) || (strcmp(cmd, "right") == 0) || (strcmp(cmd, "left") == 0)){
		CmdNode *new = NULL;
		new = (CmdNode*)calloc(1, sizeof(CmdNode));
		strcpy(new -> cmd, cmd);
		new -> val = val;
		new -> next = NULL;
		return new;
	}
	printf("Invalid command.\n");	
	return NULL;
}

/*---------------------------------------------------------------------------*/

void printCommandList(CmdNode *head) {
  /**
   * This function prints out each command in the linked list one after the 
   * other. Each command MUST also have a line number printed before it, this 
   * is what you will be using to modify / delete them. To do this, initialize 
   * a counter and then increment it for each command.
   * 
   * Depending on whether or not the command needs an additional value 
   * (like forward, backward and colour), use one of the following statements 
   * to print out the information for each node: 
   *            [ The format is "linenumber: command value" ]
   * 
   * printf("%3d: %s %d\n", ... );     [With a value]
   * 
   * printf("%3d: %s\n", ... );        [Without a value]
   * 
   * Obviously, you also need to pass in the correct parameters to the print 
   * function yourself, this is just so you have the correct format.
   * 
   * TODO: Implement this function
   */
   
	int count = 0;
	CmdNode *p = NULL;
	p = head;
	
	while(p != NULL){
		if((strcmp(p -> cmd, "forward") == 0) || (strcmp(p -> cmd, "backward") == 0) || (strcmp(p -> cmd, "colour") == 0)){
			printf("%3d: %s %d\n", count, p -> cmd, p -> val);
		}
		else if((strcmp(p -> cmd, "penup") == 0) || (strcmp(p -> cmd, "pendown") == 0) || (strcmp(p -> cmd, "right") == 0) || (strcmp(p -> cmd, "left") == 0)){
			printf("%3d: %s\n", count, p -> cmd);
		}
		p = p -> next;
		count++;
	}
}

/*---------------------------------------------------------------------------*/

void queryByCommand(CmdNode *head, char cmd[10]) {
  /**
   * This function looks for commands in the linked list that match the input 
   * query. It prints them out in the same format as the printCommandList() 
   * function.
   * 
   * Make sure that the line number of the commands that match is the same as 
   * the line number that would be printed by the printCommandList() function.
   * 
   * --------------------------------------------------------------------------
   * 
   * For instance, if your printCommandList function outputs
   * 
   *    0: penup
   *    1: forward 200
   *    2: right
   *    3: forward 50
   * 
   * Then, if this function is called with the same list and cmd = "forward", 
   * then your output here should be
   * 
   *    1: forward 200
   *    3: forward 50
   * 
   * TODO: Implement this function
   */
	
	int count = 0;
	CmdNode *p = NULL;
	p = head;
	
	while(p != NULL){
		if(strcmp(p -> cmd, cmd) == 0){
			if((strcmp(p -> cmd, "forward") == 0) || (strcmp(p -> cmd, "backward") == 0) || (strcmp(p -> cmd, "colour") == 0)){
				printf("%3d: %s %d\n", count, p -> cmd, p -> val);
			}
			else if((strcmp(p -> cmd, "penup") == 0) || (strcmp(p -> cmd, "pendown") == 0) || (strcmp(p -> cmd, "right") == 0) || (strcmp(p -> cmd, "left") == 0)){
				printf("%3d: %s\n", count, p -> cmd);
			}
		}
		count++;
		p = p -> next;
	}
}

/*---------------------------------------------------------------------------*/

int countCommands(CmdNode *head) {
  /**
   * This function counts and returns the length of the linked list. It 
   * requires list traversal.
   * 
   * TODO: Implement this function
   */
	
	int count = 0;
	CmdNode *p = NULL;
	p = head;
	
	while(p != NULL){
		count++;
		p = p -> next;
	}
	return count;
}

/*---------------------------------------------------------------------------*/

CmdNode *insertCommand(CmdNode *head, CmdNode *new_CmdNode) {
  /**
   * This function inserts the node new_CmdNode *at the tail* of the linked 
   * list. (You are adding a command at the end).
   * 
   * If head == NULL, then the linked list is still empty.
   * 
   * It returns a pointer to the head of the linked list with the new node 
   * added into it.
   * 
   * TODO: Implement this function
   */
   
	if(head == NULL){
        head = new_CmdNode;
		return head;
    }
	
	CmdNode *p = NULL;
	p = head;
	
	while(p -> next != NULL){
		p = p -> next;
	}
    p -> next = new_CmdNode;
	
    return head;
}

/*---------------------------------------------------------------------------*/

CmdNode *insertCommandBefore(CmdNode *head, CmdNode *new_CmdNode, int cmdNum) {
  /**
   * This function inserts a new node *before* a given Node in the linked list. 
   * 
   * 'cmdNum' is an integer that corresponds to the line number of a command 
   * from the printCommandList() function. Your task is to insert new_CmdNode 
   * *before* the corresponding node in the linked list.
   *
   * --------------------------------------------------------------------------
   *  
   * For instance, if your initial list was
   * 
   *    0: penup
   *    1: forward 200
   *    2: right
   *    3: forward 50
   * 
   * And you added "pendown" before cmdNum = 2, then you will have
   * 
   *    0: penup
   *    1: forward 200
   *    2: pendown
   *    3: right
   *    4: forward 50
   * 
   * --------------------------------------------------------------------------
   * 
   * If there is no command with the given cmdNum (cmdNum >= list size), 
   * then print "Invalid Command Number.\n" to the screen and *do not* 
   * insert the new node.
   * 
   * Returns a pointer to the head of the linked list with the new node added 
   * into it.
   * 
   * TODO: Implement this function
   */
		
    
    if(head == NULL){
        return new_CmdNode;
    }

    if(cmdNum == 0){
        new_CmdNode -> next = head;
        return new_CmdNode;
    }
	
	if(cmdNum > countCommands(head) || cmdNum < 0){
        printf("Invalid Command Number.\n");
        return head;
    }
	
	CmdNode *p = NULL;
	p = head;
    int count = 0;
	
    while(count < cmdNum - 1){
        count++;
		p = p -> next;
    }
    new_CmdNode -> next = p -> next;
    p -> next = new_CmdNode;
    return head;
}

/*---------------------------------------------------------------------------*/
	
void updateCommand(CmdNode *head, int cmdNum, char cmd[10], int val) {
  /**
   * This function updates a specific node in the linked list based on the 
   * input parameters.
   * 
   * 'cmdNum' is an integer that corresponds to the line number of a command 
   * from the printCommandList() function. Your task is to update the 'cmd' and 
   * 'val' fields of this node.
   * 
   * If there is no command with the given cmdNum, then print 
   * "Invalid Command Number.\n" to the screen, and if 'cmd' is not a correct 
   * command, then print "Invalid command.\n". In both these cases, do *not* 
   * modify the list.
   * 
   * TODO: Implement this function
   */
	
	if(cmdNum <= countCommands(head) && cmdNum >= 0){
		if((strcmp(cmd, "forward") == 0) || (strcmp(cmd, "backward") == 0) || (strcmp(cmd, "colour") == 0) || 
		(strcmp(cmd, "penup") == 0) || (strcmp(cmd, "pendown") == 0) || (strcmp(cmd, "right") == 0) || (strcmp(cmd, "left") == 0)){
			CmdNode *p = NULL;
			p = head;
			int count = 0;
			while(p != NULL){
				if(count == cmdNum){
					strcpy(p -> cmd, cmd);
					p -> val = val;
				}
				count++;
				p = p -> next;
			}
		}
		else{
			printf("Invalid Command.\n");
		}
	}
	else{
		printf("Invalid Command Number.\n");
	}
}	
	
/*---------------------------------------------------------------------------*/
	
CmdNode *deleteCommand(CmdNode *head, int cmdNum) {
  /**
   * This function deletes the node from the linked list that corresponds to 
   * the line number cmdNum. If there is no command with the given cmdNum, then 
   * the function does nothing.
   * 
   * Returns a pointer to the head of the linked list (which may have changed 
   * as a result of the deletion)
   *
   * TODO: Implement this function
   */
	
	if(head == NULL){
		return NULL;
	}
	
	if(cmdNum > countCommands(head) || cmdNum < 0){
		return NULL;
	}
	
	CmdNode *p, *q = NULL;
	p = head;
	q = head -> next;
	int count = 0;
	
	if(cmdNum == 0){
		free(p);
		return q;
	}
	
	while(q != NULL){
		if(count == cmdNum - 1){
			p -> next = q -> next;
			free(q);
			break;
		}
		count++;
		q = q -> next;
		p = p -> next;	
	}
	return head;
}	

/*---------------------------------------------------------------------------*/

CmdNode *deleteCommandList(CmdNode *head) {
  /**
   * This function deletes the linked list of commands, releasing all the 
   * memory allocated to the nodes in the linked list.
   * 
   * Returns a NULL pointer so that the head of the list can be set to NULL
   * after deletion.
   * 
   * TODO: Implement this function
   */
   
	CmdNode *p, *q = NULL;
	p = head;
	while(p != NULL){
		q = p -> next;
		free(p);
		p = q;
	}
	head = NULL;
	return head;
}

/*---------------------------------------------------------------------------*/

void run(Image *im, CmdNode *head, int *endX, int *endY) {
  /**
   * This function runs the list of commands to move the turtle around and draw 
   * the image, and returns the final position of the turtle in the variables 
   * endX and endY.
   * 
   * --------------------------------------------------------------------------
   * 
   * NOTE: In the image we work with, the top-left pixel is (0,0),
   *       - x increases as you go right, up till SIZEX-1
   *       - y increases as you go down, up till SIZEY-1
   * 
   *                 (0,0)                 (SIZEX-1, 0)
   *                   x------------------------x
   *                   |                        |
   *                   |                        |
   *                   |                        |
   *                   |                        |
   *                   |          IMAGE         |
   *                   |                        |
   *                   |                        |
   *                   |                        |
   *                   |                        |
   *                   |                        |
   *                   x------------------------x
   *             (0, SIZEY-1)            (SIZEX-1, SIZEY-1)
   * 
   * The image is in grayscale (black and white), so the colours are numbers 
   * from [0-255] where 0 is black, 255 is white, and the values in between 
   * are varying levels of gray.
   * 
   * You need to understand how the (x,y) values are stored so you know how 
   * they should be updated when you move (down means y increases, etc). You do 
   * not need to use the 'im' variable for anything other than passing it into 
   * the drawLine() function described below.
   * 
   * --------------------------------------------------------------------------
   * 
   * Here's the setup - There is a turtle (with a pen) that walks along the 
   * image. When the pen is down (on the paper), it draws a line along the path 
   * that it walks on. (If you want to play around with this, consider looking 
   * at the `turtle` library in python!)
   * 
   * The turtle initially starts at pixel (0, 0) [at the top left], 
   * facing right (in the positive x direction). The pen starts off
   * as `down`, with the default colour being black (0).
   * 
   * You need to go through the linked list and 'run' the commands to keep 
   * track of the turtles position, and draw the appropriate lines. Here is 
   * what each command should do:
   * 
   *  - penup          : Put the pen up (stop drawing)
   *  - pendown        : Put the pen down (start / continue drawing)
   *  - colour <val>   : Draw lines in colour <val> from now on
   *  - forward <val>  : Move the turtle forward <val> steps (pixels) 
   *                     in the direction it is facing.
   *  - backward <val> : Same as above, except move backwards
   *  - right          : Turn the turtle to the right by 90 degrees
   *  - left           : Turn the turtle to the left by 90 degrees
   * 
   * NOTE: Make sure that you do *not* go outside the image. For this, set the 
   * maximum and minimum values of x and y to be 0 and SIZEX-1 / SIZEY-1 
   * respectively.
   * 
   * For instance, if the turtle is at (0,0) facing right, and your command is
   * `forward 100000`, it will only go forward till (SIZEX-1, 0), and end 
   * up at the rightmost pixel in that row.
   * 
   * IMPORTANT: Once you are done with all the commands, make sure you save the 
   * final (x,y) location of the turtle into the variables endX and endY.
   * 
   * --------------------------------------------------------------------------
   * 
   * We have already implemented a drawLine() function (in imgUtils.c) which 
   * you should use to actually draw the lines. It takes in the following:
   * 
   *      - a pointer to an image struct (use 'im')
   *      - (x,y) location of start point
   *      - (x,y) location of end point
   *      - a colour to draw the line in [0-255]
   *          
   * Note that this function only draws horizontal and vertical lines, so 
   * either the x values or the y values of both points must be the same. 
   * Both these points *must* also be within the image. 
   *          [ 0 <= x < SIZEX,  0 <= y < SIZEY ]
   * 
   * 
   * TODO: Implement this function
   */
	
    int x_cord = 0;
	int y_cord = 0;
	int col = 0;
	int dir = 0;
	int down = 1;
	CmdNode *p = NULL;
	p = head;
	
    while(p != NULL){
        if(strcmp(p -> cmd, "penup") == 0){
            down = 0;
        } 
		else if(strcmp(p -> cmd, "pendown") == 0){
            down = 1;
        } 
		else if(strcmp(p -> cmd, "forward") == 0){
            int x = x_cord;
            int y = y_cord;
            if(dir == 0){
                x = x + (p -> val);
                if(x > SIZEX - 1){
					x = SIZEX - 1;
				}
            }
			else if(dir == 1){
                y = y + (p -> val);
                if(y > SIZEY - 1){
					y = SIZEY - 1;
				}
            }
			else if(dir == 2){
                x = x - (p -> val);
                if(x < 0){
					x = 0;
				}
            } 
			else if(dir == 3){
                y = y - (p -> val);
                if(y < 0){
					y = 0;
				}
            }
            if(down == 1){
                drawLine(im, x_cord, y_cord, x, y, col);
            }
            x_cord = x;
            y_cord = y;
        }
		else if(strcmp(p -> cmd, "backward") == 0){
            int x = x_cord;
            int y = y_cord;
            if(dir == 0){
                x = x - (p -> val);
                if(x < 0){
					x = 0;
				}
            } 
			else if(dir == 1){
                y = y - (p -> val);
                if(y < 0){
					y = 0;
				}
            } 
			else if(dir == 2){
                x = x + (p -> val);
                if(x > SIZEX - 1){
					x = SIZEX - 1;
				}
            } 
			else if(dir == 3){
                y = y + (p -> val);
                if(y > SIZEY - 1){
					y = SIZEY - 1;
				}
            }
            if(down == 1){
                drawLine(im, x_cord, y_cord, x, y, col);
            }
            x_cord = x;
            y_cord = y;
        } 
		else if(strcmp(p -> cmd, "colour") == 0){
            col = p -> val;
        } 
		else if(strcmp(p -> cmd, "right") == 0){
			if(dir == 3){
				dir = 0;
			}
			else{
				dir = dir + 1;
			}
		}
		else if(strcmp(p -> cmd, "left") == 0){
			if(dir == 0){
				dir = 3;
			}
			else{
				dir = dir - 1;
			}
		}
        p = p -> next;
    }
    *endX = x_cord;
    *endY = y_cord;
}
/*---------------------------------------------------------------------------*/
// All done!