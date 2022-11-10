#include <rte_eal.h>
#include <rte_lcore.h>

#include <iostream>
#include <thread>

using namespace std::literals;

int worker(void *) {
  int cid = ::rte_lcore_id();
  std::cout << "core " << cid << ", tid=" << std::this_thread::get_id()
            << std::endl;

  std::this_thread::sleep_for(1s);

  return 0;
}

int main(int argc, char **argv) {

  //
  int r = ::rte_eal_init(argc, argv);
  std::cout << "rte_eal_init=" << r << std::endl;
  if (r < 0) {
    std::cerr << "Initialization failed\n";
    return 1;
  }

  unsigned i;
  RTE_LCORE_FOREACH_WORKER(i) { ::rte_eal_remote_launch(worker, NULL, i); }

  worker(nullptr);

  ::rte_eal_mp_wait_lcore();

  std::cout << "cleaning up " << std::endl;
  ::rte_eal_cleanup();
}
