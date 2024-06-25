#include <iostream>

int scoreCalc(int bids, int tricks,int bags, int currentBags, int score);
int bagsCalc(int bids, int tricks,int bags, int currentBags, int score);
void scoreShow(std::string player1, std::string player2, int score1, int score2, int bags1, int bags2);
void winnerShow(std::string player1, std::string player2, int score1, int score2);

int main(){

    std::string player1,player2;
    int score1;
    int score2;
    int currentBags1;
    int currentBags2;
    int bids1, bids2, tricks1, tricks2;
    int bags1;
    int bags2;

    std::cout << "***SPADES SCORE CALCULATOR***" << std::endl;
    std::cout << "Enter the first player: ";
    std::getline(std::cin, player1);
    std::cout << "Enter the second player: ";
    std::getline(std::cin, player2);
    std::cout << "Enter current score of " << player1 << ". Enter 0 if starting new game: \n";
    std::cin >> score1;
    std::cout << "Enter current score of " << player2 << ". Enter 0 if starting new game: \n";
    std::cin >> score2;
    std::cout << "Enter current bags of " << player1 << ". Enter 0 if starting new game: \n";
    std::cin >> bags1;
    std::cout << "Enter current bags of " << player2 << ". Enter 0 if starting new game: \n";
    std::cin >> bags2;

    do{
        std::cout << player1 << ", What do you bid? ";
        std::cin >> bids1;
        std::cout << player2 << ", What do you bid? ";
        std::cin >> bids2;
        std::cout << "How many tricks did " << player1 << " take? ";
        std::cin >> tricks1;
        std::cout << "How many tricks did " << player2 << " take? ";
        std::cin >> tricks2;

        bags1 = bagsCalc(bids1, tricks1, bags1, currentBags1, score1);
        bags2 = bagsCalc(bids2, tricks2, bags2, currentBags2,score2);

        score1 = scoreCalc(bids1, tricks1, bags1, currentBags1, score1);
        score2 = scoreCalc(bids2, tricks2, bags2, currentBags2, score2);

        if (bags1 >= 10){
        bags1 = bags1%10;
        }
        else if (bags2 >= 10){
        bags2 = bags2%10;
        }

        scoreShow(player1,player2, score1, score2, bags1, bags2);

    }while(score1 < 500 && score2 < 500);

    winnerShow(player1, player2, score1, score2);

    return 0;
}

void scoreShow(std::string player1, std::string player2, int  score1, int score2, int bags1, int bags2){
    std::cout << "---CURRENT SCORE---" << std::endl;
    std::cout << player1 << ": " << score1 << ", Bags = " << bags1 << ", To win: " << 500 - score1 << std::endl;
    std::cout << player2 << ": " << score2 << ", Bags = " << bags2 << ", To win: " << 500 - score2 << std::endl;
    std::cout << "-------------------\n";
}

int scoreCalc(int bids, int tricks, int bags, int currentBags, int score){

    if (bids == 0 && tricks == 0){
        score += 100;
    }
    else if (bids == 0 && tricks != 0){
        score -= 100;
    }

    if (bids != 0){
        if (tricks >= bids){
        currentBags = tricks - bids;
        score += bids*10 + currentBags;
        }
        else if (tricks < bids){
            score -= 10*bids;
        }

        if (bags >= 10){
            score -= 100*(bags/10);
        }
    }
    

    return score;
    
}

void winnerShow(std::string player1, std::string player2, int score1, int score2){
    if (score1 >= 500 && score1 > score2){
        std::cout << player1 << " wins!\n";
    }
    else if (score2 >= 500 && score2 > score1){
        std::cout << player2 << " wins!\n";
    }

    std::cout << "**************";
}

int bagsCalc(int bids, int tricks, int bags, int currentBags, int score){

    if (bids != 0){
        if (tricks >= bids){
        currentBags = tricks - bids;
        bags += currentBags;   
        }
    }

    return bags;
}