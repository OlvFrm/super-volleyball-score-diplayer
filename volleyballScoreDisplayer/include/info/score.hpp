#pragma once

class Score {
friend class GameInfo;

private:

    unsigned int points_;
    unsigned int sets_;
    
public:
    
    Score();

    unsigned int getPoints() const;
    unsigned int getSets() const;
};