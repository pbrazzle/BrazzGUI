#include "BrazzCore.hpp"

//Box struct for game objects
struct Box
{
	float x,y,width,height;
};

//Global defines
Window myWindow;
Box player, opponent, ball;
bool movingUp, movingDown, inGame, playerWins;
float ballXV, ballYV;
int playerScore = 0, opponentScore = 0;

//Functions
void draw();
void handleInputs();
void moveObjects();
void checkBallCollisions();
bool colliding(Box, Box);
void initializeGame(bool);

//Main function
int BrazzApp()
{
	//Initialize Window
	myWindow.setWidth(800);
	myWindow.setHeight(400);
	myWindow.setText("Pong");
	myWindow.setResizable(false);
	
	initializeGame(true);
	
	//Show Window
	myWindow.show();
	
	//Update loop
	while (myWindow.update() > 0){
		if (inGame)
		{
			handleInputs();
			checkBallCollisions();
			moveObjects();
			draw();
		}
		else
		{
			handleInputs();
			myWindow.drawText((playerWins) ? "You win!" : "You lose!", 320, 120);
			myWindow.drawText("Press C to play again!", 270, 170);
		}
	}
	
	return 0;	
}

void initializeGame(bool full)
{
	//Set object starting positions
	player.x = 50;
	player.y = 190;
	opponent.width = player.width = 25;
	opponent.height = player.height = 80;
	
	opponent.x = 700;
	opponent.y = 0;
	
	ball.x = 390;
	ball.y = 190;
	ball.width = 20;
	ball.height = 20;
	ballXV = 0.1;
	ballYV = 0.1;
	
	movingUp = false;
	movingDown = false;
	
	if (full)
	{
		playerWins = false;
		inGame = true;
	}
}

bool colliding(Box a, Box b)
{
	//Check x values
	if ((a.x < b.x + b.width && a.x > b.x) || (b.x < a.x + a.width && b.x > a.x))
	{
		if ((a.y < b.y + b.height && a.y > b.y) || (b.y < a.y + a.height && b.y > a.y)) return true;
	}
	else return false;
}

void checkBallCollisions()
{
	//Check players
	if (colliding(ball, player)) 
	{
		ballXV = 0.1;
		ballYV = -0.1 + 0.2*(ball.y - player.y)/player.height;
	}
	else if (colliding(ball, opponent))
	{
		ballXV = -0.1;
		ballYV = -0.1 + 0.2*(ball.y - opponent.y)/opponent.height;
	}
	//Check top bottom walls
	if (ball.y <= 0 || ball.y >= myWindow.getHeight() - ball.height) ballYV = -ballYV;
	
	//Check for score
	if (ball.x < player.x + player.width - 5)
	{
		opponentScore++;
		if (opponentScore == 7)
		{
			opponentScore = playerScore = 0;
			playerWins = false;
			inGame = false;
		}
		initializeGame(false);
	} 
	else if (ball.x > opponent.x - ball.width + 5)
	{
		playerScore++;
		if (playerScore == 7)
		{
			opponentScore = playerScore = 0;
			playerWins = true;
			inGame = false;
		}
		initializeGame(false);
	}
}

void draw()
{
	myWindow.drawLine(myWindow.getWidth()/2, 0, myWindow.getWidth()/2, myWindow.getHeight());
	myWindow.drawRect(player.x,player.y,player.width,player.height);
	myWindow.drawRect(opponent.x,opponent.y,opponent.width,opponent.height);
	myWindow.drawRect(ball.x,ball.y,ball.width,ball.height);
	myWindow.drawText(std::to_string(playerScore), 370, 20);
	myWindow.drawText(std::to_string(opponentScore), 400, 20);
}

void handleInputs()
{
	while(myWindow.hasEvents())
	{
		Event e = myWindow.getNextEvent();
		switch (e.getID())
		{
			case C_KEY_PRESS:
			{
				if (!inGame) initializeGame(true);
				break;
			}
			case ARROW_UP_PRESS:
			{
				movingUp = true;
				break;
			}
			case ARROW_UP_RELEASE:
			{
				movingUp = false;
				break;
			}
			case ARROW_DOWN_PRESS:
			{
				movingDown = true;
				break;
			}
			case ARROW_DOWN_RELEASE:
			{
				movingDown = false;
				break;
			}
		}
	}
}

void moveObjects()
{
	//Move user paddle
	if (movingDown && player.y < myWindow.getHeight() - player.height) player.y += 0.1;
	if (movingUp && player.y > 0) player.y -= 0.1;
		
	//Move ball
	ball.x += ballXV;
	ball.y += ballYV;
		
	//Move opponent
	float vel = 0.11 * (ball.x/myWindow.getWidth());
	(opponent.y > ball.y-30) ? opponent.y -= vel : opponent.y += vel;
	
	//Check opponent collisions
	if (opponent.y < 0) opponent.y = 0;
	else if (opponent.y > myWindow.getHeight()-opponent.height) opponent.y = myWindow.getHeight() - opponent.height;
}