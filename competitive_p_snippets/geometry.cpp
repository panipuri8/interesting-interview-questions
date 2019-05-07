int orientation(pii a, pii b, pii c) {
    ll value = (b.ss - a.ss) * (c.ff - b.ff) - (b.ff - a.ff) * (c.ss - b.ss);
    if(value == 0) return 0; // collinear
    if(value > 0) return 1; //clockwise
    return 2; //anticlockwise
}

bool on_segment(pii a, pii b, pii c) { //if B lies on segment AC
    return (b.ff >= min(a.ff,c.ff)) && (b.ss >= min(a.ss,c.ss)) && (b.ff <= max(a.ff,c.ff)) && (b.ss <= max(a.ss,c.ss));
}

bool line_segment_intersect(pii a, pii b, pii c, pii d) { //AB and CD intersect?
    int o1 = orientation(a,b,c);
    int o2 = orientation(a,b,d);
    int o3 = orientation(c,d,a);
    int o4 = orientation(c,d,b);
    if(o1 != o2 && o3 != o4) {
        return true;
    }
    if(o1 == 0 && on_segment(a,c,b)) {
        return true;
    }
    if(o2 == 0 && on_segment(a,d,b)) {
        return true;
    }
    if(o3 == 0 && on_segment(c,a,d)) {
        return true;
    }
    if(o4 == 0 && on_segment(c,b,d)) {
        return true;
    }
    return false;
}

vector<int> convexHull(vector<pii> a, int n) { //jarvis wrapping algorithm
    if(n < 3) {
        vector<int> v;
        return v;
    }
    int leftMost = 0;
    for(int i=1;i<n;i++) {
        if(a[i].ff < a[leftMost].ff) {
            leftMost = i;
        }
    }
    vector<int> v;
    int current = leftMost;
    do {
        v.pb(current);
        int next = (current+1)%n;
        for(int i=0;i<n;i++) {
            if(orientation(a[current],a[i],a[next]) == 2) {
                next = i;
            }
        }
        current = next;
    } while(current != leftMost);
    return v;
}

ld area(int ax, int ay, int bx, int by, int cx, int cy) { //area of tr
    return (abs(ax*(by-cy) + bx*(cy-ay) + cx*(ay-by)))/(2.00);
}