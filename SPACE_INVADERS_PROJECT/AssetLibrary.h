#pragma once
#include <string>
#include <vector>
/*
Example presented in class 11/9/2015.

Problem: Loading textures should only happen once per texture.
What's a good way to 'propagate' that handle throughout or program?

In other words- How do we simplify accessing assets we've loaded in?

One way is to create an alias or binding for each texture by creating
a name-value association using a map container. By keeping track
of this 'privately' (as a static global variable in the .cpp), we
won't make mistakes with how we use it, because ONLY these functions
can interface with that data.

For future reference, this scheme allows us to create strong associations
with animation data!!!!

See the .cpp for implementation details.
*/

void loadTexture(const std::string &name, const char *path,
	unsigned r, unsigned c);

unsigned getTexture(const std::string &name);



unsigned getFrame(const std::string &tname,
	const std::string &aname,
	unsigned frame);

unsigned getAnimationLength(const std::string &tname,
	const std::string &aname);


float getAnimationDuration(const std::string &tname,
	const std::string &aname);

void addAnimation(const std::string &tname,
	const std::string &aname,
	const std::vector<unsigned> &frames,
	float frameRate = 12.f);

unsigned sampleAnimation(const std::string &tname,
	const std::string &aname,
	float timePassed, float speed = 1.f, bool loop = true);

unsigned int getSubHeight(const std::string &name, unsigned c, unsigned scale); //used to make collison easier

unsigned int getSubWidth(const std::string &name, unsigned r, unsigned scale);