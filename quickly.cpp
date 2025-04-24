// 62 second
// #include <algorithm>
// #include <vector>
// #include <iostream>
// #include <random>
// #include <chrono>
// #include <thread>
// #include <mutex>
// #include <queue>
// #include <condition_variable>
// #include <atomic>

// // 定义地图大小
// const int MAP_WIDTH = 10000;
// const int MAP_HEIGHT = 10000;

// // 定义起点和终点
// const std::pair<int, int> START_POINT = {0, 0};
// const std::pair<int, int> END_POINT = {MAP_WIDTH - 1, MAP_HEIGHT - 1};

// // 地图表示，0为可通行，1为障碍
// std::vector<std::vector<int>> generate_random_map(int width, int height, double obstacle_prob) {
//     std::vector<std::vector<int>> map(height, std::vector<int>(width, 0));
//     std::mt19937_64 rng(std::random_device{}());
//     std::uniform_real_distribution<double> dist(0.0, 1.0);
    
//     for(int y = 0; y < height; ++y) {
//         for(int x = 0; x < width; ++x) {
//             if(std::make_pair(x, y) == START_POINT || std::make_pair(x, y) == END_POINT)
//                 continue;
//             map[y][x] = (dist(rng) < obstacle_prob) ? 1 : 0;
//         }
//     }
//     return map;
// }

// // 定义方向
// const std::vector<std::pair<int, int>> DIRECTIONS = {
//     {1, 0}, {-1, 0}, {0, 1}, {0, -1}
// };

// // 线程安全的队列
// template <typename T>
// class ConcurrentQueue {
// private:
//     std::queue<T> queue_;
//     std::mutex mutex_;
// public:
//     void push(const T& value) {
//         std::lock_guard<std::mutex> lock(mutex_);
//         queue_.push(value);
//     }
    
//     bool pop(T& result) {
//         std::lock_guard<std::mutex> lock(mutex_);
//         if(queue_.empty())
//             return false;
//         result = queue_.front();
//         queue_.pop();
//         return true;
//     }
    
//     bool empty() {
//         std::lock_guard<std::mutex> lock(mutex_);
//         return queue_.empty();
//     }
// };

// // 并行广度优先搜索（BFS）实现
// bool parallel_bfs(const std::vector<std::vector<int>>& map, 
//                  const std::pair<int, int>& start, 
//                  const std::pair<int, int>& end, 
//                  int num_threads) {
//     std::vector<std::vector<bool>> visited(map.size(), std::vector<bool>(map[0].size(), false));
//     ConcurrentQueue<std::pair<int, int>> queue;
//     queue.push(start);
//     visited[start.second][start.first] = true;
//     std::atomic<bool> found(false);
    
//     auto worker = [&](int thread_id) {
//         while(!found.load()) {
//             std::pair<int, int> current;
//             if(!queue.pop(current)) {
//                 // 如果队列为空，等待一段时间后继续检查
//                 std::this_thread::sleep_for(std::chrono::milliseconds(1));
//                 continue;
//             }
            
//             for(const auto& dir : DIRECTIONS) {
//                 int new_x = current.first + dir.first;
//                 int new_y = current.second + dir.second;
                
//                 // 检查边界
//                 if(new_x < 0 || new_x >= MAP_WIDTH || new_y < 0 || new_y >= MAP_HEIGHT)
//                     continue;
                
//                 // 检查障碍
//                 if(map[new_y][new_x] == 1)
//                     continue;
                
//                 // 检查是否已访问
//                 {
//                     // 使用锁保护访问
//                     static std::mutex visit_mutex;
//                     std::lock_guard<std::mutex> lock(visit_mutex);
//                     if(visited[new_y][new_x])
//                         continue;
//                     visited[new_y][new_x] = true;
//                 }
                
//                 // 检查是否到达终点
//                 if(std::make_pair(new_x, new_y) == end) {
//                     found.store(true);
//                     return;
//                 }
                
//                 // 将新位置加入队列
//                 queue.push({new_x, new_y});
//             }
//         }
//     };
    
//     // 创建并启动线程
//     std::vector<std::thread> threads;
//     for(int i = 0; i < num_threads; ++i) {
//         threads.emplace_back(worker, i);
//     }
    
//     // 等待所有线程完成
//     for(auto& th : threads) {
//         th.join();
//     }
    
//     return found.load();
// }

// int main() {
//     // 生成随机地图
//     std::cout << "生成随机地图..." << std::endl;
//     double obstacle_probability = 0.3; // 30%的概率为障碍
//     auto start_time = std::chrono::high_resolution_clock::now();
//     std::vector<std::vector<int>> map = generate_random_map(MAP_WIDTH, MAP_HEIGHT, obstacle_probability);
//     auto end_time = std::chrono::high_resolution_clock::now();
//     std::chrono::duration<double> map_duration = end_time - start_time;
//     std::cout << "地图生成完成，耗时: " << map_duration.count() << " 秒\n";
    
//     // 执行并行搜索
//     int num_threads = std::thread::hardware_concurrency();
//     if(num_threads == 0) num_threads = 4; // 默认使用4个线程
//     std::cout << "使用线程数: " << num_threads << std::endl;
    
//     std::cout << "开始并行搜索..." << std::endl;
//     start_time = std::chrono::high_resolution_clock::now();
//     bool path_found = parallel_bfs(map, START_POINT, END_POINT, num_threads);
//     end_time = std::chrono::high_resolution_clock::now();
//     std::chrono::duration<double> search_duration = end_time - start_time;
    
//     if(path_found)
//         std::cout << "搜索成功，找到路径！\n";
//     else
//         std::cout << "搜索失败，没有找到路径。\n";
//     std::cout << "搜索耗时: " << search_duration.count() << " 秒\n";
    
//     return 0;
// }
//11 second
// #include <algorithm>
// #include <vector>
// #include <iostream>
// #include <random>
// #include <chrono>
// #include <thread>
// #include <atomic>
// #include <mutex>
// #include <queue>
// #include <future>
// #include <immintrin.h>
// #include <omp.h>

// // 定义地图大小
// const int MAP_WIDTH = 10000;
// const int MAP_HEIGHT = 10000;

// // 定义起点和终点
// const std::pair<int, int> START_POINT = {0, 0};
// const std::pair<int, int> END_POINT = {MAP_WIDTH - 1, MAP_HEIGHT - 1};

// // 地图表示，0为可通行，1为障碍
// std::vector<std::vector<int>> generate_random_map(int width, int height, double obstacle_prob) {
//     std::vector<std::vector<int>> map(height, std::vector<int>(width, 0));
//     std::mt19937_64 rng(std::random_device{}());
//     std::uniform_real_distribution<double> dist(0.0, 1.0);

//     // 使用OpenMP并行化地图生成
//     #pragma omp parallel for schedule(static)
//     for(int y = 0; y < height; ++y) {
//         // 为每个线程创建独立的随机数生成器，避免竞争
//         std::mt19937_64 thread_rng(rng());
//         for(int x = 0; x < width; ++x) {
//             if(std::make_pair(x, y) == START_POINT || std::make_pair(x, y) == END_POINT)
//                 continue;
//             map[y][x] = (dist(thread_rng) < obstacle_prob) ? 1 : 0;
//         }
//     }
//     return map;
// }

// // 定义方向，包括八个方向（增加对角线移动）
// const std::vector<std::pair<int, int>> DIRECTIONS = {
//     {1, 0}, {-1, 0}, {0, 1}, {0, -1},
//     {1, 1}, {-1, -1}, {1, -1}, {-1, 1}
// };

// // 并行广度优先搜索（BFS）优化实现
// bool parallel_bfs_optimized(const std::vector<std::vector<int>>& map, 
//                             const std::pair<int, int>& start, 
//                             const std::pair<int, int>& end, 
//                             int num_threads) {
//     // 使用一维向量表示访问状态，并初始化为false
//     std::vector<std::atomic<bool>> visited(MAP_WIDTH * MAP_HEIGHT);
//     for(auto &v : visited)
//         v.store(false);
    
//     // 双队列用于当前层和下一层
//     std::vector<std::pair<int, int>> current_level;
//     std::vector<std::pair<int, int>> next_level;
//     current_level.emplace_back(start);
//     visited[start.second * MAP_WIDTH + start.first].store(true);
//     std::atomic<bool> found(false);
    
//     while(!current_level.empty() && !found.load()) {
//         next_level.clear();

//         // 并行处理当前层的所有节点
//         #pragma omp parallel for num_threads(num_threads) schedule(dynamic, 1000)
//         for(size_t i = 0; i < current_level.size(); ++i) {
//             if(found.load()) continue;

//             auto current = current_level[i];
//             for(const auto& dir : DIRECTIONS) {
//                 int new_x = current.first + dir.first;
//                 int new_y = current.second + dir.second;

//                 // 检查边界
//                 if(new_x < 0 || new_x >= MAP_WIDTH || new_y < 0 || new_y >= MAP_HEIGHT)
//                     continue;

//                 // 检查障碍
//                 if(map[new_y][new_x] == 1)
//                     continue;

//                 // 原子操作检查和设置访问状态
//                 size_t index = new_y * MAP_WIDTH + new_x;
//                 bool expected = false;
//                 if(visited[index].compare_exchange_strong(expected, true)) {
//                     // 检查是否到达终点
//                     if(std::make_pair(new_x, new_y) == end) {
//                         found.store(true);
//                         break;
//                     }

//                     // 线程安全地将新节点加入下一层
//                     #pragma omp critical
//                     next_level.emplace_back(new_x, new_y);
//                 }
//             }
//         }

//         // 交换队列
//         current_level.swap(next_level);
//     }

//     return found.load();
// }

// int main() {
//     // 生成随机地图
//     std::cout << "生成随机地图..." << std::endl;
//     double obstacle_probability = 0.3; // 30%的概率为障碍
//     auto start_time = std::chrono::high_resolution_clock::now();
//     std::vector<std::vector<int>> map = generate_random_map(MAP_WIDTH, MAP_HEIGHT, obstacle_probability);
//     auto end_time = std::chrono::high_resolution_clock::now();
//     std::chrono::duration<double> map_duration = end_time - start_time;
//     std::cout << "地图生成完成，耗时: " << map_duration.count() << " 秒\n";
    
//     // 执行并行搜索
//     int num_threads = std::thread::hardware_concurrency();
//     if(num_threads == 0) num_threads = 8; // 默认使用8个线程
//     std::cout << "使用线程数: " << num_threads << std::endl;
    
//     std::cout << "开始并行搜索..." << std::endl;
//     start_time = std::chrono::high_resolution_clock::now();
//     bool path_found = parallel_bfs_optimized(map, START_POINT, END_POINT, num_threads);
//     end_time = std::chrono::high_resolution_clock::now();
//     std::chrono::duration<double> search_duration = end_time - start_time;
    
//     if(path_found)
//         std::cout << "搜索成功，找到路径！\n";
//     else
//         std::cout << "搜索失败，没有找到路径。\n";
//     std::cout << "搜索耗时: " << search_duration.count() << " 秒\n";
    
//     return 0;
// }
#include <algorithm>
#include <vector>
#include <iostream>
#include <random>
#include <chrono>
#include <thread>
#include <atomic>
#include <mutex>
#include <queue>
#include <immintrin.h>
#include <omp.h>

// 定义地图大小
const size_t MAP_WIDTH = 100000;   // 宽度
const size_t MAP_HEIGHT = 50000;   // 高度

// 定义起点和终点
const std::pair<size_t, size_t> START_POINT = {0, 0};
const std::pair<size_t, size_t> END_POINT = {MAP_WIDTH - 1, MAP_HEIGHT - 1};

// 地图表示，0为可通行，1为障碍（使用一维数组）
std::vector<uint8_t> generate_random_map(size_t width, size_t height, double obstacle_prob) {
    std::vector<uint8_t> map(width * height, 0);
    std::mt19937_64 rng(std::random_device{}());
    std::uniform_real_distribution<double> dist(0.0, 1.0);

    // 使用OpenMP并行化地图生成
    #pragma omp parallel for schedule(static)
    for(size_t y = 0; y < height; ++y) {
        // 为每个线程创建独立的随机数生成器，避免竞争
        std::mt19937_64 thread_rng(rng());
        for(size_t x = 0; x < width; ++x) {
            if((x == START_POINT.first && y == START_POINT.second) || 
               (x == END_POINT.first && y == END_POINT.second))
                continue;
            map[y * width + x] = (dist(thread_rng) < obstacle_prob) ? 1 : 0;
        }
    }
    return map;
}

// 定义八个方向（包括对角线）
const std::vector<std::pair<int, int>> DIRECTIONS = {
    {1, 0}, {-1, 0}, {0, 1}, {0, -1},
    {1, 1}, {-1, -1}, {1, -1}, {-1, 1}
};

// 双向广度优先搜索（Bidirectional BFS）优化实现
bool bidirectional_bfs(const std::vector<uint8_t>& map, 
                       const std::pair<size_t, size_t>& start, 
                       const std::pair<size_t, size_t>& end, 
                       int num_threads) {
    // 使用一维向量表示访问状态
    std::vector<std::atomic<bool>> visited_forward(map.size());
    std::vector<std::atomic<bool>> visited_backward(map.size());

    // 初始化访问状态
    #pragma omp parallel for num_threads(num_threads) schedule(static)
    for(size_t i = 0; i < map.size(); ++i) {
        visited_forward[i].store(false, std::memory_order_relaxed);
        visited_backward[i].store(false, std::memory_order_relaxed);
    }

    // 初始化队列
    std::vector<std::pair<size_t, size_t>> queue_forward;
    std::vector<std::pair<size_t, size_t>> queue_backward;
    queue_forward.emplace_back(start);
    queue_backward.emplace_back(end);
    visited_forward[start.second * MAP_WIDTH + start.first].store(true, std::memory_order_relaxed);
    visited_backward[end.second * MAP_WIDTH + end.first].store(true, std::memory_order_relaxed);

    // 标志是否找到路径
    std::atomic<bool> found(false);

    while(!queue_forward.empty() && !queue_backward.empty() && !found.load()) {
        // 扩展前向队列
        std::vector<std::pair<size_t, size_t>> next_queue_forward;
        #pragma omp parallel for num_threads(num_threads) schedule(dynamic, 1000)
        for(size_t i = 0; i < queue_forward.size(); ++i) {
            if(found.load()) continue;
            auto current = queue_forward[i];
            for(const auto& dir : DIRECTIONS) {
                ssize_t new_x = static_cast<ssize_t>(current.first) + dir.first;
                ssize_t new_y = static_cast<ssize_t>(current.second) + dir.second;

                // 检查边界
                if(new_x < 0 || new_x >= static_cast<ssize_t>(MAP_WIDTH) ||
                   new_y < 0 || new_y >= static_cast<ssize_t>(MAP_HEIGHT))
                    continue;
                
                size_t new_x_u = static_cast<size_t>(new_x);
                size_t new_y_u = static_cast<size_t>(new_y);
                size_t index = new_y_u * MAP_WIDTH + new_x_u;

                // 检查障碍
                if(map[index] == 1)
                    continue;

                // 原子操作检查和设置访问状态
                bool expected = false;
                if(visited_forward[index].compare_exchange_strong(expected, true)) {
                    // 检查是否在后向访问中被访问过
                    if(visited_backward[index].load(std::memory_order_relaxed)) {
                        found.store(true);
                        break;
                    }
                    // 线程安全地将新节点加入下一层
                    #pragma omp critical
                    next_queue_forward.emplace_back(new_x_u, new_y_u);
                }
            }
        }
        if(found.load()) break;
        queue_forward.swap(next_queue_forward);

        // 扩展后向队列
        std::vector<std::pair<size_t, size_t>> next_queue_backward;
        #pragma omp parallel for num_threads(num_threads) schedule(dynamic, 1000)
        for(size_t i = 0; i < queue_backward.size(); ++i) {
            if(found.load()) continue;
            auto current = queue_backward[i];
            for(const auto& dir : DIRECTIONS) {
                ssize_t new_x = static_cast<ssize_t>(current.first) + dir.first;
                ssize_t new_y = static_cast<ssize_t>(current.second) + dir.second;

                // 检查边界
                if(new_x < 0 || new_x >= static_cast<ssize_t>(MAP_WIDTH) ||
                   new_y < 0 || new_y >= static_cast<ssize_t>(MAP_HEIGHT))
                    continue;
                
                size_t new_x_u = static_cast<size_t>(new_x);
                size_t new_y_u = static_cast<size_t>(new_y);
                size_t index = new_y_u * MAP_WIDTH + new_x_u;

                // 检查障碍
                if(map[index] == 1)
                    continue;

                // 原子操作检查和设置访问状态
                bool expected = false;
                if(visited_backward[index].compare_exchange_strong(expected, true)) {
                    // 检查是否在前向访问中被访问过
                    if(visited_forward[index].load(std::memory_order_relaxed)) {
                        found.store(true);
                        break;
                    }
                    // 线程安全地将新节点加入下一层
                    #pragma omp critical
                    next_queue_backward.emplace_back(new_x_u, new_y_u);
                }
            }
        }
        if(found.load()) break;
        queue_backward.swap(next_queue_backward);
    }

    return found.load();
}

int main() {
    // 生成随机地图
    std::cout << "生成随机地图..." << std::endl;
    double obstacle_probability = 0.3; // 30%的概率为障碍
    auto start_time = std::chrono::high_resolution_clock::now();
    std::vector<uint8_t> map = generate_random_map(MAP_WIDTH, MAP_HEIGHT, obstacle_probability);
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> map_duration = end_time - start_time;
    std::cout << "地图生成完成，耗时: " << map_duration.count() << " 秒\n";

    // 执行双向并行搜索
    int num_threads = std::thread::hardware_concurrency();
    if(num_threads == 0) num_threads = 8; // 默认使用8个线程
    std::cout << "使用线程数: " << num_threads << std::endl;

    std::cout << "开始双向并行搜索..." << std::endl;
    start_time = std::chrono::high_resolution_clock::now();
    bool path_found = bidirectional_bfs(map, START_POINT, END_POINT, num_threads);
    end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> search_duration = end_time - start_time;

    if(path_found)
        std::cout << "搜索成功，找到路径！\n";
    else
        std::cout << "搜索失败，没有找到路径。\n";
    std::cout << "搜索耗时: " << search_duration.count() << " 秒\n";

    return 0;
}