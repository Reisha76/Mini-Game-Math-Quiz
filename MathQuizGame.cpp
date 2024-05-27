#include <iostream>
using namespace std;

enum enQuestionDifficulty {Easy=1,Medium=2,Hard=3,Mix=4};
enum enOperationType {Addition=1, Subtraction=2,Multiplication=3,Division=4,MixOps=5};
enum enWonOrLost {Win=1,Lose=2};

struct stQuizInfo
{
    short NumOfQuestions;
    enQuestionDifficulty QuestionDifficulty;
    enOperationType OperationType;
     
    short UserScore=0;
    string WonOrLostGame;
};

struct stRoundInfo
{
    char operation;
    short operand1;
    short operand2;

    enWonOrLost WonOrLostRound;
};

void ResetScreen()
{
    system("cls");
    system("color 0F");
}

short RandomNumber(short From, short To)
{
    short randNum = rand() % (To - From + 1) + From;
    return randNum;
}

string Tabs(short NumberOfTabs)
{
    string t;
    for (int i = 1; i < NumberOfTabs; i++)
    {
        t = t + "\t";
        cout << t;
    }
    return t;
}

short ReadNumOfQuestions()
{
    short NumOfQuestions;

    cout << "How many questions do you want to answer ? ";
    cin >> NumOfQuestions;

    return NumOfQuestions;
}

enQuestionDifficulty ReadQuestionDifficulty()
{
    short choice;
    do
    {
        cout << "Choose Difficulty of Questions: [1]: Easy, [2]: Medium, [3]: Hard, [4]: Mix ";
        cin >> choice;
    } while (choice < 1 || choice>4);
 
    return (enQuestionDifficulty) choice;
}

enOperationType ReadOperationType()
{
    short choice;
    do
    {
        cout << " Choose operation of Questions: [1]: Addition, [2]: Subtraction, [3]: Multiplication, [4]: Division, [5]: Mix ";
        cin >> choice;
    } while (choice < 1 || choice>5);
    

    return (enOperationType) choice;
}

stRoundInfo QuestionGenerator(stQuizInfo &QuizInfo)
{
    stRoundInfo RoundInfo;

    enQuestionDifficulty ForStatScreen=QuizInfo.QuestionDifficulty;
    enOperationType ForStatScreen2 = QuizInfo.OperationType;

    if (ForStatScreen ==enQuestionDifficulty::Mix)
        ForStatScreen =(enQuestionDifficulty)RandomNumber(1, 3);

    switch (ForStatScreen)
    {
    case enQuestionDifficulty::Easy:
        RoundInfo.operand1 = RandomNumber(1, 10);
        RoundInfo.operand2 = RandomNumber(1, 10);
        break;
    case enQuestionDifficulty::Medium:
        RoundInfo.operand1 = RandomNumber(11, 40);
        RoundInfo.operand2 = RandomNumber(11, 40);
        break;
    case enQuestionDifficulty::Hard:
        RoundInfo.operand1 = RandomNumber(41, 99);
        RoundInfo.operand2 = RandomNumber(41, 99);
        break;
    }

    if (ForStatScreen2 == enOperationType::MixOps)
        ForStatScreen2 = (enOperationType)RandomNumber(1, 4);

    switch (ForStatScreen2)
    {
    case enOperationType::Addition:
        RoundInfo.operation = '+';
        break;
    case enOperationType::Subtraction:
        RoundInfo.operation = '-';
        break;
    case enOperationType::Multiplication:
        RoundInfo.operation = '*';
        break;
    case enOperationType::Division:
        RoundInfo.operation = '/';
        break;
    }
    return RoundInfo;
}

void PrintQuestion(stRoundInfo RoundInfo)
{
    cout << RoundInfo.operand1 << endl;
    cout << RoundInfo.operand2 << " " << RoundInfo.operation << endl << endl;
    cout << "________________\n";
}

string CheckQuestionAnswer(stRoundInfo &RoundInfo, short PlayerAnswer,stQuizInfo &QuizInfo)
{
    string AnswerResult;
    short answer;

    switch (RoundInfo.operation)
    {
    case '+':
        answer = RoundInfo.operand1 + RoundInfo.operand2;
        break;
    case '-':
        answer = RoundInfo.operand1 - RoundInfo.operand2;
        break;
    case '*':
        answer = RoundInfo.operand1 * RoundInfo.operand2;
        break;
    case '/':
        answer = RoundInfo.operand1 / RoundInfo.operand2;
        break;
    }
    if (answer == PlayerAnswer)
    {
        AnswerResult = "Correct Answer! :-)\n";
        RoundInfo.WonOrLostRound = enWonOrLost::Win;
        QuizInfo.UserScore++;
    }
    else
    {
        AnswerResult = "Incorrect Answer! :-(\n";
        RoundInfo.WonOrLostRound = enWonOrLost::Lose;
    }
    return AnswerResult;
}

void SetScreenColor(stRoundInfo RoundInfo)
{
    if (RoundInfo.WonOrLostRound == enWonOrLost::Win)
        system("color 2F");
    else
        system("color 4F");
}

string CheckGameResult(stQuizInfo QuizInfo)
{
    if (QuizInfo.NumOfQuestions % 2 != 0)
    {
        if (QuizInfo.UserScore >= (QuizInfo.NumOfQuestions / 2) + 1)
            return QuizInfo.WonOrLostGame = "PASS";
        else
            return QuizInfo.WonOrLostGame = "FAILED";
    }
    else
    {
        if (QuizInfo.UserScore >= QuizInfo.NumOfQuestions / 2)
            return QuizInfo.WonOrLostGame = "PASS";
        else
            return QuizInfo.WonOrLostGame = "FAILED";
    }
}

string GetDifficulty(stQuizInfo QuizInfo)
{
    switch (QuizInfo.QuestionDifficulty)
    {
    case enQuestionDifficulty::Easy:
        return "Easy";
    case enQuestionDifficulty::Medium:
        return "Medium";
    case enQuestionDifficulty::Hard:
        return "Hard";
    case enQuestionDifficulty::Mix:
        return "Mix";
    }

}

string GetOperationType(stQuizInfo QuizInfo)
{
    switch (QuizInfo.OperationType)
    {
    case enOperationType::Addition:
        return "Addition";
    case enOperationType::Subtraction:
        return "Subtraction";
    case enOperationType::Multiplication:
        return "Multiplication";
    case enOperationType::Division:
        return "Division";
    case enOperationType::MixOps:
        return "Mix";
    default:
        break;
    }

}

void GameOverScreen(stQuizInfo &QuizInfo)
{
    string Face;
    if (CheckGameResult(QuizInfo) == "PASS")
    {
        system("color 2F");
         Face = ":-)";
    }
    else
    {
        system("color 4F");
         Face = ":-(";

    }
    cout << "----------------------------------------------------\n\n";
    cout << Tabs(2) << "Final result is " << CheckGameResult(QuizInfo) << " " << Face << endl << endl;
    cout << "----------------------------------------------------\n\n";
    cout << "Number of Questions         : " << QuizInfo.NumOfQuestions << endl;
    cout << "Questions Difficulty        : " << GetDifficulty(QuizInfo) << endl;
    cout << "Type of operation           : " << GetOperationType(QuizInfo) << endl;
    cout << "Number of Correct Answers   : " << QuizInfo.UserScore<<endl;
    cout << "Number of Incorrect Answers : " << QuizInfo.NumOfQuestions - QuizInfo.UserScore<<endl<<endl;
    
}

void PlayGame(stQuizInfo &QuizInfo)
{
    short signed PlayerAnswer;
    for (int i = 1; i <= QuizInfo.NumOfQuestions; i++)
    {
        cout << "Question [" << i << "/" << QuizInfo.NumOfQuestions << "]\n\n";
        
        stRoundInfo RoundInfo=QuestionGenerator(QuizInfo);
        PrintQuestion(RoundInfo);
        cin >> PlayerAnswer;
        cout << CheckQuestionAnswer(RoundInfo, PlayerAnswer,QuizInfo);
        SetScreenColor(RoundInfo);
    }

}

void StartGame()
{
    

    char PlayAgain = 'Y';

    do
    {
        ResetScreen();
        stQuizInfo QuizInfo;
        stRoundInfo RoundInfo;

        QuizInfo.NumOfQuestions = ReadNumOfQuestions();
        QuizInfo.QuestionDifficulty = ReadQuestionDifficulty();
        QuizInfo.OperationType = ReadOperationType();
        PlayGame(QuizInfo);
        GameOverScreen(QuizInfo);

        cout << "Do you want to play again? Y/N? ";
        cin >> PlayAgain;
    } while (PlayAgain == 'Y' || PlayAgain == 'y');
 
}

int main()
{
    srand((unsigned)time(NULL));
    
    StartGame();
    return 0;
}


