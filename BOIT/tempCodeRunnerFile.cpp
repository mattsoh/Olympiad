t<<findB(str)<<endl;
	for (int c = simplified.length()-1;c>=0;c--){
		if (simplified[c] == 'O') i = O(i);
		if (simplified[c] == 'E') i = E(i);
		if (simplified[c] == 'T') i = T(i);
	}
	cout<<i