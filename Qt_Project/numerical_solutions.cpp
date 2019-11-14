#ifndef NUMERICAL_SOLUTIONS_H
#define NUMERICAL_SOLUTIONS_H

#include <cmath>
#include <stdexcept>
#include <utility>
#include <vector>

class ode_solver {
protected:
    typedef double real;
    typedef std::pair<real, real> point;

public:
    virtual std::vector<point> solve_interval(real rhs(real, real), point p0,
                                              real x,
                                              unsigned int precision) = 0;
    std::vector<point> operator()(real rhs(real, real), point p0, real x,
                                  unsigned int precision) {
        return solve_interval(rhs, p0, x, precision);
    }

    virtual ~ode_solver() = default;
};

template <unsigned int stages>
class explicit_runge_kutta_solver_base : public ode_solver {
    static_assert(stages > 0,
                  "The number of stages in explicit_runge_kutta_solver "
                  "instantiation must be strictly positive.\n");

protected:
    std::vector<std::vector<real>> butcher_a;
    std::vector<real> butcher_b, butcher_c;

    explicit_runge_kutta_solver_base() {
        butcher_a.resize(stages);
        butcher_b.resize(stages);
        butcher_c.resize(stages);
        for (unsigned int i = 0; i < stages; i++)
            butcher_a[i].resize(i);
    }

    void internal_set_butcher_a(const std::vector<std::vector<real>> &new_a) {
        if (new_a.size() != stages)
            throw std::invalid_argument(
                "Size of new_a must be exactly the number of stages.\n");
        for (unsigned int i = 0; i < stages; i++) {
            if (new_a[i].size() != i)
                throw std::invalid_argument(
                    "Size of new_a[i] must be exactly i.\n");
        }
        butcher_a = new_a;
    }

    void internal_set_butcher_b(const std::vector<real> &new_b) {
        if (new_b.size() != stages)
            throw std::invalid_argument(
                "Size of new_b must be exactly the number of stages.\n");
        butcher_b = new_b;
    }

    void internal_set_butcher_c(const std::vector<real> &new_c) {
        if (new_c.size() != stages)
            throw std::invalid_argument(
                "Size of new_c must be exactly the number of stages.\n");
        butcher_c = new_c;
    }

#define X first
#define Y second

public:
    std::vector<point> solve_interval(real rhs(real, real), point p0, real x,
                                      unsigned int precision) override {
        if (precision == 0)
            throw std::invalid_argument(
                "Precision must be strictly greater than 0.\n");
        if (x < p0.X)
            throw std::invalid_argument("x must be greater than x0.\n");

        std::vector<point> ret(precision + 1);
        real dx = (x - p0.X) / precision;

        ret[0] = p0;
        for (unsigned int i = 1; i < precision + 1; i++) {
            std::vector<real> incr(stages);
            real dy = 0.0;

            for (unsigned int j = 0; j < stages; j++) {
                real cur = 0.0;
                for (unsigned int k = 0; k < j; k++)
                    cur += butcher_a[j][k] * incr[k];

                incr[j] = rhs(p0.X + butcher_c[j] * dx, p0.Y + dx * cur);
                dy += butcher_b[j] * incr[j];
            }

            dy *= dx;

            p0.X += dx, p0.Y += dy;
            ret[i] = p0;
        }
        return ret;
    }

#undef X
#undef Y
};

class euler_method_solver : public explicit_runge_kutta_solver_base<1> {
public:
    euler_method_solver() : explicit_runge_kutta_solver_base<1>() {
        internal_set_butcher_a({{}});
        internal_set_butcher_b({1.0});
        internal_set_butcher_c({0.0});
    }
};

class improved_euler_method_solver
    : public explicit_runge_kutta_solver_base<2> {
public:
    improved_euler_method_solver() : explicit_runge_kutta_solver_base<2>() {
        internal_set_butcher_a({{}, {1}});
        internal_set_butcher_b({0.5, 0.5});
        internal_set_butcher_c({0.0, 1.0});
    }
};

class RK4_solver : public explicit_runge_kutta_solver_base<4> {
public:
    RK4_solver() : explicit_runge_kutta_solver_base<4>() {
        internal_set_butcher_a({{}, {0.5}, {0.0, 0.5}, {0.0, 0.0, 1.0}});
        internal_set_butcher_b({1.0 / 6.0, 1.0 / 3.0, 1.0 / 3.0, 1.0 / 6.0});
        internal_set_butcher_c({0.0, 0.5, 0.5, 1.0});
    }
};

#endif
