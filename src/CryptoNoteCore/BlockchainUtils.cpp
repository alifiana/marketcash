/*
 * Copyright (c) 2018, The MarketCash Developers.
 * Portions Copyright (c) 2012-2017, The CryptoNote Developers, The Bytecoin Developers.
 *
 * This file is part of MarketCash.
 *
 * This file is subject to the terms and conditions defined in the
 * file 'LICENSE', which is part of this source code package.
 */

#include "BlockchainUtils.h"

namespace CryptoNote {
namespace Utils {

bool restoreCachedTransactions(const std::vector<BinaryArray>& binaryTransactions,
                               std::vector<CachedTransaction>& transactions) {
  transactions.reserve(binaryTransactions.size());

  for (auto binaryTransaction : binaryTransactions) {
    Transaction transaction;
    if (!fromBinaryArray(transaction, binaryTransaction)) {
      return false;
    }

    transactions.emplace_back(std::move(transaction));
  }

  return true;
}

}
}
