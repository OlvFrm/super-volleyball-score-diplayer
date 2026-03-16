#pragma once


class TeamInfo {
friend class GameInfo;

private:

    unsigned int score_;
    unsigned int set_;
    bool serve_;

public:

    TeamInfo();
};