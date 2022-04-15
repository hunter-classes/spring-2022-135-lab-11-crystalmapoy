#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "profile.h"
#include "network.h"

TEST_CASE("TASK A") {
	Profile p1 = {"marco", "Marco"};
	Profile p2 = {"mario", "Mario"};

	CHECK(p1.getUsername() == "marco");
    CHECK(p1.getFullName() == "Marco (@marco)");
	
    CHECK(p2.getUsername() == "mario");
    CHECK(p2.getFullName() == "Mario (@mario)");
    
}

TEST_CASE("TASK B") {
	Network nw;
	CHECK(nw.addUser("mario", "Mario") == true);
	CHECK(nw.addUser("luigi", "Luigi") == true);
	CHECK(nw.addUser("mario", "notmario") == false);
	CHECK(nw.addUser("luigi", "notluigi") == false);
}

TEST_CASE("TASK C") {
	Network nw;
	nw.addUser("mario", "Mario");
	nw.addUser("luigi", "Luigi");
	nw.addUser("yoshi", "Yoshi");

	CHECK(nw.follow("mario", "luigi") == true);
	CHECK(nw.follow("mario", "yoshi") == true);
	CHECK(nw.follow("luigi", "mario") == true);
}