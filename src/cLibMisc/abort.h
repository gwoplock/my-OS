/*
 * abort.h
 *
 *  Created on: Aug 15, 2017
 *      Author: garrett
 */

#ifndef SRC_CLIBMISC_ABORT_H_
#define SRC_CLIBMISC_ABORT_H_

#include "../global.h"


#if defined(__cplusplus)
extern "C" {/* Use C linkage for kernel_main. */
#endif
void abort(void);
#if defined(__cplusplus)
}/* Use C linkage for kernel_main. */
#endif

#endif /* SRC_CLIBMISC_ABORT_H_ */
