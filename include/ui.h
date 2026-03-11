#ifndef UI_H
#define UI_H

enum Screen
{
  SCREEN_BOOT,
  SCREEN_DASHBOARD,
  SCREEN_MENU
};

extern Screen currentScreen;

void initUI();
void updateUI();

#endif