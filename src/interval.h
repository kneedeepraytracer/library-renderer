#pragma once

namespace kdrt::renderer {
    class Interval {
    public:
        double min;
        double max;

        Interval();
        Interval(double min, double max);

        double size() const;
        bool contains(double x) const;
        bool surrounds(double x) const;
        double clamp(double x) const;

        static const Interval empty;
        static const Interval universe;
    };
}