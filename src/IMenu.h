#ifndef IMENU_H
#define IMENU_H

class IMenu {
public:
	virtual void update() = 0;
	virtual void setParent(IMenu* parent) = 0;
	virtual ~IMenu() {};
};

#endif