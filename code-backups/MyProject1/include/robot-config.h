using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor FL_Drive;
extern motor FR_Drive;
extern motor RL_Drive;
extern motor RR_Drive;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );