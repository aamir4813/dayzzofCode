void removeZeros(string &s) {
  int i = 0;
  int n = s.size();
  while (i < n && s[i] == '0') {
    i++;
  }

  s =  s.substr(i, n - i);
}

int Solution::power(string s) {
  removeZeros(s);
  string dividend = s;
  string quotient = "";
  int rem = 0;

  int n = 0;
  int i = 0;
  int base = 0;
  while (1) {
    quotient = "";
    n = dividend.size();
    i = 0;
    rem = 0;
    while (i < n) {
      base = (rem * 10 + (dividend[i] - '0')) / 2;
      quotient += (base + '0');
      rem = (rem * 10 + (dividend[i] - '0')) % 2;
      i++;
    }
    if(rem == 0 && quotient.size() == 1 && quotient[0] == '1' ) {
      return true;
    } else if (rem == 1) {
      return false;
    }
    removeZeros(quotient);
    dividend = quotient;
  }
}
