#ifndef SPHERE_H
#define SPHERE_H

#include "vec3.h"
#include "hittable.h"

class sphere : public hittable 
{
    public:
        sphere(point3 _center, double _radius) : center(_center), radius(_radius) {}

        bool hit(const ray &ray, interval ray_t, hit_record &rec) const override
        {
            vec3 oc = ray.origin() - center;
            auto a = ray.direction().length_squared();
            auto half_b = dot(oc, ray.direction());
            auto c = oc.length_squared() - radius * radius;
            auto discr = half_b * half_b - a * c;
            
            if (discr < 0) return false;
            auto sqrtd = sqrt(discr);

            // FIND NEAREAST ROOT IN THE INTERVAL
            auto root = (-half_b - sqrtd) / a;
            if (!ray_t.surrounds(root))
            {
                // CHECK FOR THE OTHER SOLUTION
                root = (-half_b + sqrtd) / a;
                if (!ray_t.surrounds(root)) return false;
            }

            rec.t = root;
            rec.p = ray.at(rec.t);
            vec3 outward_normal = (rec.p - center) / radius;
            rec.set_face_normal(ray, outward_normal);

            return true;
        }

    private:
        point3 center;
        double radius;
};

#endif