#include <iostream>
#include <string>
#include "RiddleStatues.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

RiddleStatues::RiddleStatues() {
    introductionSeen = false;
    riddle1Answered = false;
    riddle2Answered = false;
    riddle3Answered = false;
    exited = false;
}

void RiddleStatues::barrier() {
    if (!introductionSeen)
    {
        cout << "\nAs you're enveloped by the green light of the barrier, you hear a deep voice reverberate in your mind. As it speaks within your head, the eyes of the first stone to your left glow green." << endl
            << "Deep Voice: 'And so another seeks the warriors weapon, but it is a long journey from here.'" << endl
            << "Another voice begins to speak, far less deep and cackling, like the voice of someone telling a proud joke. Now the middle stones eyes glow in the emerald sheen." << endl
            << "Cackling Voice: 'Ooooh yesss! Another lends an ear! I sure cannot wait too see them wallow in disappointment and shed a tear!'" << endl
            << "A third voice joins, now calm and sweet as a mothers. And as with the others, the third stones eyes shine." << endl
            << "Kindly Voice: 'Do not worry my dear, there is nothing to fear, It has just been so long since a person has arrived to hear...'" << endl
            << "Deep Voice: 'We are the riddle stones, keeping a treasure close and near.'" << endl
            << "Cackling Voice: 'Yes yes yes! I wonder if you will be the one to take the treasure from our lear!'" << endl
            << "Kindly Voice: 'So answer our riddles and once complete, our existence in defense of the treasure will be finally obsolete...'\n" << endl;
        introductionSeen = true;
        string answer;
        cout << "\nNow all turns quiet, and the statues no longer glow." << endl
            << "Kindly Voice: 'Are you ready child?' Mutters the female statue, eyes once again shining. 'When you start, there is only truth or loss.'" << endl
            << "Kindly Voice: Are you ready?: " << endl << "> ";
        getline(cin, answer);

        while (answer != "yes" && answer != "Yes" && answer != "no" && answer != "No")
        {
            cout << "\nKindly Voice: 'What was that? The answer only requires a yes or no child...'" << endl
                << "Kindly Voice: 'And so I ask again, are you ready?': " << endl << "> ";
            cin >> answer;
        }

        if (answer == "no" || answer == "No")
        {
            cout << "\nKindly Voice: 'Then we will wait for you to be ready.'" << endl
                << "The jester statue makes a sound akin to a scoff." << endl
                << "Cackling Voice: 'And what else would we doooo??? We are here for eternity unless someone answers the riddles anyway!'" << endl
                << "The warrior statue grumbles in response." << endl
                << "Deep Voice: 'I believe in this one. They will find the answers.'" << endl
                << "And with that, you step out of the barrier, and all goes silent in your head once more.\n" << endl;
            exited = true;
            return;
        }
        if (answer == "yes" || answer == "Yes")
        {
            Riddles();
        }
    }
}

void RiddleStatues::Riddles() {

    if (exited)
    {
        string answer;
        cout << "\nYou step back into the barrier and a voice enters your mind." << endl
            << "Kindly Voice: 'I assume that you are ready now?':" << endl << "> ";
        cin >> answer;
        while (answer != "yes" && answer != "Yes" && answer != "no" && answer != "No")
        {
            cout << "\nKindly Voice: 'What was that? The answer only requires a yes or no child...'" << endl
                << "Kindly Voice: 'And so I ask again, are you ready?':" << endl << "> ";
            cin >> answer;
        }
        if (answer == "yes" || answer == "Yes")
        {
            cout << "Kindly Voice: 'Then let us begin...'\n";
        }
        if (answer == "no" || answer == "No")
        {
            cout << "Kindly Voice: 'Then why step into the barrier at all child? Return when you are truly ready...'";
            return;
        }
    }
    if (!riddle1Answered && !riddle2Answered && !riddle3Answered) {
        string answer1;
        cout << "The crystal lights around the room begin to flicker. Then, darkness hits. In the darkness you hear all three voices come upon you at once." << endl
            << "Statues: 'There are three riddles you will answer. One after another intelligence will be tested. Answering right will lead you to the next, answering wrong will lead you out of the barrier.'" << endl
            << "After the voices die down, The lights come again, revealing only the leftmost statue, the statue of the man holding the sword." << endl
            << "Deep Voice: 'Some try to hide, some try to cheat, but time will show, we always will meet. Try as you might, to guess my name, I promises you'll know when you, I do claim... And so, what is my name?': " << endl << "> ";
        cin >> answer1;
        if (answer1 == "death" || answer1 == "Death")
        {
            cout << "\nDeep Voice: 'That... Is my name.'" << endl
                << "And with that, the lights flicker off again and death grows finally silent.\n";
            riddle1Answered = true;
        }
        else {
            cout << "\nDeep Voice: 'That... Is not my name...'" << endl
                << "Before your mind can even conclude that you got the answer wrong, you feel yourself forcefully tugged out of the barrier. As you hit the ground, the lights return to normal, and the room lays unchanged.";
            return;
        }
    }

    if (riddle1Answered && !riddle2Answered && !riddle3Answered)
    {
        string answer2;
        cout << "\nThe crystal lights around the room begin to flicker. Then, darkness hits. In the darkness you hear the voices of the remaining two statues." << endl
            << "Statues: 'One done, two left, will your brain be up to the next?'" << endl
            << "When the voices quiet, the lights flicker to life, revealing the jester." << endl
            << "Cackling Voice: 'With thieves I consort, with the vilest, in short. I'm quite at ease in depravity, yet all divines use me. And much so savants can't lose me, for I am their center of gravity! Oooh Hooo! What is my name!?':" << endl << "> ";
        cin >> answer2;
        if (answer2 == "V" || answer2 == "v" || answer2 == "letter v" || answer2 == "the letter v")
        {
            cout << "\nCackling Voice: 'Oh you are a smart one indeed! Yes you have my name!'" << endl
                << "The lights once again cease, and V the Jester falls silent, perhaps for the first time in millennium.\n";
            riddle2Answered = true;
        }
        else {
            cout << "\nCackling Voice: 'OH HU! No, " << answer2 << " is not my name! Try again, buster!'" << endl
                << "Before your mind can even conclude that you got the answer wrong, you feel yourself forcefully tugged out of the barrier. As you hit the ground, the lights return to normal, and the room lays unchanged.";
            return;
        }
    }

    if (riddle1Answered && riddle2Answered && !riddle3Answered)
    {
        string answer3;
        cout << "\nThe crystal lights around the room begin to flicker. Then, darkness hits. In the darkness you hear the voices of the final statue." << endl
            << "Kindly Voice: 'Oh I am so proud, how far you have come! You are so close to freeing us and being done! One more riddle I will hum and soon oh soon you will have won...'" << endl
            << "The lights arrive once more, revealing the statue of the women, elegant and regal even in stone." << endl
            << "Kindly Voice: 'In halls of stone, I sit on high, with golden crown that touches the sky. I command with grace, yet fight with might, in day I rule, in shadows, ignite. What is my name?':" << endl << "> ";
        cin >> answer3;
        if (answer3 == "queen" || answer3 == "Queen")
        {
            cout << "\nKindly Voice: 'Yes! You have it! That is indeed my name.'" << endl
                << "And now Queen loses her light, like the others.\n";
            riddle3Answered = true;
        }
        else
        {
            cout << "\nKindly Voice: 'No, that is not my name...'" << endl
                << "Before your mind can even conclude that you got the answer wrong, you feel yourself forcefully tugged out of the barrier. As you hit the ground, the lights return to normal, and the room lays unchanged.";
            return;
        }
    }

    if (riddle1Answered && riddle2Answered && riddle3Answered)
    {
        cout << "\nNow, with all answers given, the statues groan to life once more, the lights firing brighter now than before. Bright spots focus on a crystal dais coming up from the ground before the statues, atop it, a radiant green orb shines in emerald light.\n" << endl
            << "And once again, the statues begin to speak.\n" << endl
            << "Statues: 'Together now, we stand as three, your wisdom hath set us free. In this green orb, our thanks we give. Take it forth, and may you live. Now with fortunes smile, and tales to tell, of how you broke our ancient spell...'\n" << endl
            << "And as the light fades forever from the statues eyes, the green orb sits awaiting your touch. You walk up towards the dais and take the orb.\n" << endl
            << "\nYOU HAVE OBTAINED THE GREEN ORB\n\n";
        cin.ignore();
    }
}
