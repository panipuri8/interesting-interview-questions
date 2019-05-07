ld low = 0, high = dr;
while((high-low) > 1e-3) {
    ld mid1 = low + (high - low)/3;
    ld mid2 = high - (high - low)/3;
    ld val1 = calculate(mid1);
    ld val2 = calculate(mid2);
    if(val1 > val2) {
        low = mid1;
    }
    else {
        high = mid2;
    }
}

double ts(double start, double end)
{
    double l = start, r = end;

    for(int i=0; i<200; i++) {
      double l1 = (l*2+r)/3;
      double l2 = (l+2*r)/3;
      if(func(l1) > func(l2)) 
        r = l2; 
      else l = l1;
      }

     double x = l;
    return func(x);
}