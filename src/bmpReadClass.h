
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

#ifndef _BMPREADCLASS_H_INCLUDED_
#define _BMPREADCLASS_H_INCLUDED_

class imagen {
private:
  unsigned int magic_number;
  unsigned int img_num;
  unsigned int row_num;
  unsigned int col_num;

public:
void header();
};

#endif
