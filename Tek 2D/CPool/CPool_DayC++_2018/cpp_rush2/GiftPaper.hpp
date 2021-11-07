//
// EPITECH PROJECT, 2018
// GiftPaper.hpp
// File description:
// Gift Paper header
//

#ifndef GIFTPAPER_H_
#define GIFTPAPER_H_

#include <string>
#include "Wrap.hpp"

class GiftPaper : public Wrap
{
protected:

public:
        GiftPaper();
	virtual ~GiftPaper();
	virtual void wrapMeThat(Object *gift);
};

#endif /* GIFTPAPER_H_ */
