#include <iostream>
#include "Moe.h"

using std::cout;
using std::endl;

Moe::Moe() {
    hasTalked = false;
    hasKey = false;
    sideQuestFinished = false;
}

void Moe::InteractMoe() {
    {
        if (!hasTalked)
        {
            cout << "\nYou shout at the skeleton." << endl
                << "Skeleton: 'What? You talkin' to me?'" << endl
                << "The voice emanating from the skeleton is rough as sandpaper. You ask the skeleton if they have anything that could help you." << endl
                << "Skeleton: 'Huh? Do I have a what? Well I don't know, do YOU have anything that could help ME?'" << endl
                << "The skeleton taps their boney fingers pensively on the stone they hold." << endl
                << "Skeleton: 'Well. If you do... I may have something for you.'" << endl
                << "The skeleton goes back to reading their... stone..? " << endl
                << "Just as you begin to turn, you hear - 'The name's Moe by the way.'\n" << endl;
            hasTalked = true;
        }
        else if (hasTalked && !hasKey && !sideQuestFinished)
            cout << "\nMoe: 'What? I already told you I need some convincing to give anything I may have in my possession. Something shiny would be nice... So get looking!'\n" << endl;
        else if (hasTalked && hasKey && !sideQuestFinished) {
            cout << "\nMoe: 'Yes yes, thanks for the ring. It goes nicely on my long slender fingers, don't you think?'" << endl
                << "They flash their left ring finger at you, flaunting the ring that sits upon it before going back to their tablet\n" << endl;
            sideQuestFinished = true;
        }
        else cout << "\nMoe has nothing to say.\n" << endl;
    }
};

void Moe::giveMoe() {
    cout << "\nMoe eyes(sockets?) the ring with interest." << endl
        << "Moe: 'Yes... What a marvelous ring. And you would give this to little old me?'" << endl
        << "The skeleton snatches the ring before you can react." << endl
        << "Moe: 'Yes. I think this will do quite nicely.'" << endl
        << "Moe houses the ring upon their left ring finger and raises their hand palm out to inspect the ring, now upon on their hand." << endl
        << "Moe: You have done well to find something this interesting in such a dreary place as this... Honestly I expected I was sending you on a wild goose chase!'" << endl
        << "The skeleton cackles at their words in an unpleasant, grinding sound before putting their hand down and reaching under the lawn chair they sat upon." << endl
        << "Moe: 'Here.'" << endl
        << "Moe pulls a long, bronze key from under the chair and hands it to you." << endl
        << "Moe: 'That key is about the most interesting thing I have. So interesting that I've spend no short a time trying to find where it belongs. Perhaps you will do better.'" << endl
        << "And with that, Moe goes back to staring at their stone tablet and is once again ignoring you.\n" << endl;
    hasKey = true;
    cout << "\nYou have given Moe your Golden Ring in exchange for a Bronze Key!\n" << endl;
}
