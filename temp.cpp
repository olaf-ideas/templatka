#include <bits/stdc++.h>
using namespace std;

template<class T>
struct SegTree{
  vector<T> t, p;
  T d, e;
  int base;
  //     size, default value, default return
  SegTree(int n, T _d=0, T _e=1e9+5) : d(_d), e(_e), base(1 << (32 - __builtin_clz(n - 1))){
    t.resize(base << 1, d), p.resize(base << 1, d);
  }
  T f(T l, T r){  // ask
    return min(l, r);
  }
  T g(T x, T v){  // upd
    return x + v;
  }
  void lazy(int u){
    t[u] = g(t[u], p[u]);
    if(u < base)  p[u << 1] = g(p[u << 1], p[u]), p[u << 1 | 1] = g(p[u << 1 | 1], p[u]);
    p[u] = d;
  }
  void upd(int l, int r, T v, int x=0, int y=-1, int u=1){
    lazy(u);
    if(y < 0) y += base;
    if(r < x || y < l)    return;
    if(l <= x && y <= r){
      p[u] = g(p[u], v);
      lazy(u);
      return;
    }
    int m = (x + y) >> 1;
    upd(l, r, v, x, m, u << 1);
    upd(l, r, v, m + 1, y, u << 1 | 1);
    t[u] = f(t[u << 1], t[u << 1 | 1]);
  }
  T ask(int l, int r, int x=0, int y=-1, int u=1){
    lazy(u);
    if(y < 0) y += base;
    if(r < x || y < l)    return e;
    if(l <= x && y <= r)  return t[u];
    int m = (x + y) >> 1;
    return f(ask(l, r, x, m, u << 1), ask(l, r, m + 1, y, u << 1 | 1)); 
  }
  void upd(int x, T v){upd(x, x, v);}
  T ask(int x){return ask(x, x);}

  size_t size(){return base;}
};  // olaf_surgut
