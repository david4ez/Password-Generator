#include "functions.h"

bool check(String^ q) {
	for (int i = 0; i < q->Length; i++) {
		if (isalpha(q[i]) || isspace(q[i]) || ispunct(q[i])) {
			return false;
		}
	}

	return true;
}