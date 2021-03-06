#pragma once

#include "net_raw.hpp"

template<typename activation, typename error>
Raw_Matrix raw_predict_gpu(Raw_FeedForward_Network<activation, error> & network, Raw_Matrix & input);

template<typename activation, typename error>
void raw_train_batch_gpu(Raw_FeedForward_Network<activation, error> & network,
    Raw_Matrix & inputs, Raw_Matrix & targets, int batch_size, float learning_rate, float momentum);

Raw_Matrix * matrix_to_gpu(Raw_Matrix & source);
Raw_Matrix matrix_to_cpu(Raw_Matrix * d_matrix);
void free_gpu_matrix(Raw_Matrix * d_matrix);

template<typename activation, typename error>
Raw_FeedForward_Network<activation, error> * network_to_gpu(Raw_FeedForward_Network<activation, error> & source);

template<typename activation, typename error>
void network_to_cpu_free(Raw_FeedForward_Network<activation, error> * d_network,
    Raw_FeedForward_Network<activation, error> & h_network);

template<typename activation, typename error>
void free_gpu_network(Raw_FeedForward_Network<activation, error> * d_network);

template<typename activation, typename error>
void calculate_activation(int num_trials, std::vector<int> sizes,
    Raw_FeedForward_Network<activation, error> * d_network, Raw_Matrix * d_input);

template<typename activation, typename error>
void backprop(int num_trials, std::vector<int> sizes,
    Raw_FeedForward_Network<activation, error> * d_network, Raw_Matrix * d_targets, float learning_rate = 0.8f, float momentum = 0.8f);
