//十亿元素44.1554秒
// #include <algorithm>
// #include <vector>
// #include <iostream>
// #include <random>
// #include <chrono>
// #include <thread>

// // 合并两个有序子数组
// template <typename T>
// void merge(std::vector<T>& data, size_t left, size_t mid, size_t right) {
//     size_t n1 = mid - left + 1;
//     size_t n2 = right - mid;

//     // 创建临时子数组
//     std::vector<T> leftArray(n1);
//     std::vector<T> rightArray(n2);

//     for (size_t i = 0; i < n1; ++i)
//         leftArray[i] = data[left + i];
//     for (size_t j = 0; j < n2; ++j)
//         rightArray[j] = data[mid + 1 + j];

//     // 合并临时数组回原数组
//     size_t i = 0, j = 0, k = left;
//     while (i < n1 && j < n2) {
//         if (leftArray[i] <= rightArray[j]) {
//             data[k++] = leftArray[i++];
//         }
//         else {
//             data[k++] = rightArray[j++];
//         }
//     }

//     // 复制剩余元素
//     while (i < n1) {
//         data[k++] = leftArray[i++];
//     }
//     while (j < n2) {
//         data[k++] = rightArray[j++];
//     }
// }

// // 线程排序函数
// template <typename T>
// void thread_sort(std::vector<T>& data, size_t start, size_t end) {
//     std::sort(data.begin() + start, data.begin() + end);
// }

// // 并行排序函数
// template <typename T>
// void parallel_sort(std::vector<T>& data, unsigned int num_threads) {
//     std::vector<std::thread> threads;
//     size_t length = data.size();
//     size_t block_size = length / num_threads;
//     size_t start = 0;

//     // 启动多个线程排序数据块
//     for (unsigned int i = 0; i < num_threads; ++i) {
//         size_t end = (i == num_threads - 1) ? length : start + block_size;
//         threads.emplace_back(thread_sort<T>, std::ref(data), start, end);
//         start += block_size;
//     }

//     // 等待所有线程完成
//     for (auto& th : threads) {
//         th.join();
//     }

//     // 合并排序后的块
//     size_t step = block_size;
//     while (step < length) {
//         size_t left = 0;
//         size_t mid = left + step - 1;
//         size_t right = std::min(left + 2 * step - 1, length - 1);

//         if (mid < length - 1) {
//             merge(data, left, mid, right);
//         }

//         left += 2 * step;
//         step *= 2;
//     }
// }

// int main() {
//     // 数据类型
//     using DataType = int;
//     const size_t DATA_SIZE = 1000000000; // 一亿个元素

//     // 获取硬件支持的线程数量
//     unsigned int num_threads = std::thread::hardware_concurrency();
//     if (num_threads == 0) num_threads = 10; // 默认使用4个线程

//     std::cout << "使用线程数: " << num_threads << std::endl;

//     // 生成随机数据
//     std::vector<DataType> data;
//     data.reserve(DATA_SIZE);
//     std::mt19937_64 rng(std::random_device{}());
//     std::uniform_int_distribution<DataType> dist(0, DATA_SIZE);

//     for (size_t i = 0; i < DATA_SIZE; ++i) {
//         data.emplace_back(dist(rng));
//     }

//     // 记录排序前的时间
//     auto start_time = std::chrono::high_resolution_clock::now();

//     // 并行排序数据
//     parallel_sort(data, num_threads);

//     // 记录排序后的时间
//     auto end_time = std::chrono::high_resolution_clock::now();
//     std::chrono::duration<double> duration = end_time - start_time;

//     std::cout << "并行排序完成，耗时: " << duration.count() << " 秒\n";

//     // 验证排序是否正确（可选）
//     /*
//     bool sorted = std::is_sorted(data.begin(), data.end());
//     std::cout << "排序验证: " << (sorted ? "成功" : "失败") << std::endl;
//     */

//     return 0;
// }
//27.?秒
#include <algorithm>
#include <vector>
#include <iostream>
#include <random>
#include <chrono>
#include <thread>
#include <future>

// 合并两个有序子数组
template <typename T>
void merge_vectors(const std::vector<T>& left, const std::vector<T>& right, std::vector<T>& result) {
    size_t i = 0, j = 0, k = 0;
    size_t left_size = left.size();
    size_t right_size = right.size();

    while (i < left_size && j < right_size) {
        if (left[i] <= right[j]) {
            result[k++] = left[i++];
        } else {
            result[k++] = right[j++];
        }
    }

    while (i < left_size) {
        result[k++] = left[i++];
    }

    while (j < right_size) {
        result[k++] = right[j++];
    }
}

// 递归并行排序函数
template <typename T>
std::vector<T> parallel_merge_sort(const std::vector<T>& data, unsigned int depth = 0) {
    if (data.size() <= 1000000) { // 基准大小，可根据实际情况调整
        std::vector<T> sorted_data = data;
        std::sort(sorted_data.begin(), sorted_data.end());
        return sorted_data;
    }

    size_t mid = data.size() / 2;
    std::vector<T> left(data.begin(), data.begin() + mid);
    std::vector<T> right(data.begin() + mid, data.end());

    std::future<std::vector<T>> left_sort;
    std::future<std::vector<T>> right_sort;

    if (depth < std::thread::hardware_concurrency()) {
        left_sort = std::async(std::launch::async, parallel_merge_sort<T>, left, depth + 1);
        right_sort = std::async(std::launch::async, parallel_merge_sort<T>, right, depth + 1);
    } else {
        left_sort = std::async(std::launch::deferred, parallel_merge_sort<T>, left, depth + 1);
        right_sort = std::async(std::launch::deferred, parallel_merge_sort<T>, right, depth + 1);
    }

    std::vector<T> sorted_left = left_sort.get();
    std::vector<T> sorted_right = right_sort.get();

    std::vector<T> merged(data.size());
    merge_vectors(sorted_left, sorted_right, merged);

    return merged;
}

int main() {
    using DataType = int;
    const size_t DATA_SIZE = 5000000000; // 十亿个元素

    // 获取硬件支持的线程数量
    unsigned int num_threads = std::thread::hardware_concurrency();
    if (num_threads == 0) num_threads = 4; // 默认使用4个线程

    std::cout << "使用线程数: " << num_threads << std::endl;

    // 生成随机数据
    std::cout << "生成随机数据..." << std::endl;
    std::vector<DataType> data(DATA_SIZE);
    std::mt19937_64 rng(std::random_device{}());
    std::uniform_int_distribution<DataType> dist(0, DATA_SIZE);

    // 使用多线程填充数据
    auto fill_start = std::chrono::high_resolution_clock::now();
    size_t chunk_size = DATA_SIZE / num_threads;
    std::vector<std::future<void>> futures;

    for (unsigned int i = 0; i < num_threads; ++i) {
        size_t start_idx = i * chunk_size;
        size_t end_idx = (i == num_threads - 1) ? DATA_SIZE : start_idx + chunk_size;
        futures.emplace_back(std::async(std::launch::async, [&](size_t start, size_t end) {
            for (size_t j = start; j < end; ++j) {
                data[j] = dist(rng);
            }
        }, start_idx, end_idx));
    }

    for (auto& fut : futures) {
        fut.get();
    }
    auto fill_end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> fill_duration = fill_end - fill_start;
    std::cout << "数据生成完成，耗时: " << fill_duration.count() << " 秒\n";

    // 记录排序前的时间
    // auto start_time = std::chrono::high_resolution_clock::now();

    // // 执行并行归并排序
    // std::cout << "开始并行排序..." << std::endl;
    // std::vector<DataType> sorted_data = parallel_merge_sort(data);
    // auto sort_end_time = std::chrono::high_resolution_clock::now();
    // std::chrono::duration<double> sort_duration = sort_end_time - start_time;
    // std::cout << "并行排序完成，耗时: " << sort_duration.count() << " 秒\n";

    // 可选：将排序结果赋值回原数据
    // data = std::move(sorted_data);

    // 验证排序是否正确（可选）
    /*
    bool sorted_flag = std::is_sorted(sorted_data.begin(), sorted_data.end());
    std::cout << "排序验证: " << (sorted_flag ? "成功" : "失败") << std::endl;
    */

    return 0;
}