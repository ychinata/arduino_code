//#pragma once  
#ifndef __BH1750_H
#define __BH1750_H

#include <Arduino.h>

void BH1750_Init(void);
int BH1750_Read(int address);
void BH1750_GetData(void);

#endif