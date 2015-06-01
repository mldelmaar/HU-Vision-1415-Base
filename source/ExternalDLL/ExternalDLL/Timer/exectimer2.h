#ifndef _EXECTIMER_H_
#define _EXECTIMER_H_

#include "basetimer.h"
#include <string>

/** This class is used to time a command. The command can be run using the function run().
 */
class ExecTimer2 : public BaseTimer2 {
public:
	ExecTimer2();
	bool run(std::string cmd, bool resout);
};

#endif // _EXECTIMER_H_