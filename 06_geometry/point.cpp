// @desc: Punto 2D generico Pt<T> (ll o ld) con producto punto/cruz, rotacion, sgn; P = tipo por defecto
// @cx: O(1)
template <class T> struct Pt {
    T x, y;
    Pt(T x = 0, T y = 0) : x(x), y(y) {}
    bool operator<(const Pt& p) const { return tie(x, y) < tie(p.x, p.y); }
    bool operator==(const Pt& p) const { return tie(x, y) == tie(p.x, p.y); }
    Pt operator+(const Pt& p) const { return {x + p.x, y + p.y}; }
    Pt operator-(const Pt& p) const { return {x - p.x, y - p.y}; }
    Pt operator*(T d) const { return {x * d, y * d}; }
    Pt operator/(T d) const { return {x / d, y / d}; }
    T dot(const Pt& p) const { return x * p.x + y * p.y; }
    T cross(const Pt& p) const { return x * p.y - y * p.x; }
    T cross(const Pt& a, const Pt& b) const { return (a - *this).cross(b - *this); } // (a-this) x (b-this)
    T dist2() const { return x * x + y * y; }
    double dist() const { return sqrt((double)dist2()); }
    double angle() const { return atan2((double)y, (double)x); }
    Pt perp() const { return {-y, x}; }
    Pt rotate(double a) const { return {(T)(x * cos(a) - y * sin(a)), (T)(x * sin(a) + y * cos(a))}; }
    friend istream& operator>>(istream& i, Pt& p) { return i >> p.x >> p.y; }
    friend ostream& operator<<(ostream& o, const Pt& p) { return o << "(" << p.x << "," << p.y << ")"; }
};
using P = Pt<ll>;               // cambiar a Pt<ld> para geometria con reales
using coord_t = decltype(P().x);
template <class T> int sgn(T x) { return (x > EPS) - (x < -EPS); }
