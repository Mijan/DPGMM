//
// Created by jan on 26/02/19.
//

#ifndef EIGENSERIALIZATION_H
#define EIGENSERIALIZATION_H

#include <Eigen/src/Core/Matrix.h>
#include <boost/serialization/array.hpp>

namespace boost {
    namespace serialization {

        template<class Archive, class S, int Rows_, int Cols_, int Ops_, int MaxRows_, int MaxCols_>
        inline void save(Archive &ar, const Eigen::Matrix<S, Rows_, Cols_, Ops_, MaxRows_, MaxCols_> &g,
                         const unsigned int version) {
            int rows = g.rows();
            int cols = g.cols();

            ar & rows;
            ar & cols;
            ar & boost::serialization::make_array(g.data(), rows * cols);
        }

        template<class Archive, class S, int Rows_, int Cols_, int Ops_, int MaxRows_, int MaxCols_>
        inline void
        load(Archive &ar, Eigen::Matrix<S, Rows_, Cols_, Ops_, MaxRows_, MaxCols_> &g, const unsigned int version) {
            int rows, cols;
            ar & rows;
            ar & cols;
            g.resize(rows, cols);
            ar & boost::serialization::make_array(g.data(), rows * cols);
        }

        template<class Archive, class S, int Rows_, int Cols_, int Ops_, int MaxRows_, int MaxCols_>
        inline void serialize(Archive &ar, Eigen::Matrix<S, Rows_, Cols_, Ops_, MaxRows_, MaxCols_> &g,
                              const unsigned int version) {
            split_free(ar, g, version);
        }


    } // namespace serialization
} // namespace boost

#endif //EIGENSERIALIZATION_H
