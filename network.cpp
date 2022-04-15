#include <iostream>
#include "network.h"
using namespace std;

Network::Network(){
	numUsers = 0;
	for(int i = 0; i < MAX_USERS; i++) {
		for(int j = 0; j < MAX_USERS; j++) {
			following[i][j] = false;
		}
	}
}

int Network::findID(string usrn) {
	for(int i = 0; i < numUsers; i++){
		if(profiles[i].getUsername() == usrn) {
			return i;
		}
	}
	return -1;
}

bool Network::addUser(std::string usrn, std::string dspn){
    if (numUsers == MAX_USERS){ 
        return false;
    }
    for (int i = 0; i < usrn.size(); i++){
        if (!isalnum(usrn[i])){ 
            return false;
        }
    }
    if (findID(usrn) != -1) {
        return false;
    }

    profiles[numUsers] = Profile(usrn, dspn);
    numUsers++;
    return true;
}

bool Network::follow(std::string usrn1, std::string usrn2) {
	int userID1 = findID(usrn1);
    int userID2 = findID(usrn2);

    if(userID1 != -1 && userID2 != -1) {
		following[userID1][userID2] = true;
		return true;
	}
	return false;
}

void Network::printDot() {
	std::cout << "digraph {" << std::endl;
	for(int i = 0; i < numUsers; i++) {
		std::cout << "  \"@" << profiles[i].getUsername() << "\"" << std::endl;
	}

	std::cout << std::endl;

	for(int i = 0; i < numUsers; i++){
		for(int j = 0; j < numUsers; j++){
			if(following[i][j]){
				std::cout << "\t\"@" << profiles[i].getUsername() << "\"" << " -> ";
                std::cout << "\"@" << profiles[j].getUsername() << "\""<< std::endl;
			}
		}
	}
	std::cout << "}" << std::endl;
}