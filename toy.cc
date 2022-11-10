#include <rte_eal.h>
#include <rte_ethdev.h>
#include <rte_lcore.h>

#include <iostream>
#include <thread>

using namespace std::literals;

int main(int argc, char **argv) {

  // init
  int r = ::rte_eal_init(argc, argv);
  std::cout << "rte_eal_init=" << r << std::endl;
  if (r < 0) {
    std::cerr << "Initialization failed\n";
    return 1;
  }

  {
    int total = ::rte_eth_dev_count_total();
    int avail = ::rte_eth_dev_count_avail();
    std::cout << "eth ports total=" << total << ", avail=" << avail
              << std::endl;
  }

  std::cout << "cleaning up " << std::endl;
  ::rte_eal_cleanup();
}
