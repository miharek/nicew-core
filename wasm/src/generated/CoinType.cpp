// Copyright © 2022 Mihael Rek
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

#include <NiceWCore/NWCoinType.h>
#include <NiceWCore/NWPrivateKey.h>
#include <NiceWCore/NWPublicKey.h>

#include "./PrivateKey.h"
#include "./PublicKey.h"

#include <emscripten/bind.h>

using namespace emscripten;

namespace NW::Wasm {

EMSCRIPTEN_BINDINGS(Wasm_NWCoinType) {
    enum_<NWCoinType>("CoinType")
        .value("aeternity", NWCoinType::NWCoinTypeAeternity)
        .value("aion", NWCoinType::NWCoinTypeAion)
        .value("binance", NWCoinType::NWCoinTypeBinance)
        .value("bitcoin", NWCoinType::NWCoinTypeBitcoin)
        .value("bitcoinCash", NWCoinType::NWCoinTypeBitcoinCash)
        .value("bitcoinGold", NWCoinType::NWCoinTypeBitcoinGold)
        .value("callisto", NWCoinType::NWCoinTypeCallisto)
        .value("cardano", NWCoinType::NWCoinTypeCardano)
        .value("cosmos", NWCoinType::NWCoinTypeCosmos)
        .value("dash", NWCoinType::NWCoinTypeDash)
        .value("decred", NWCoinType::NWCoinTypeDecred)
        .value("digiByte", NWCoinType::NWCoinTypeDigiByte)
        .value("dogecoin", NWCoinType::NWCoinTypeDogecoin)
        .value("eos", NWCoinType::NWCoinTypeEOS)
        .value("ethereum", NWCoinType::NWCoinTypeEthereum)
        .value("ethereumClassic", NWCoinType::NWCoinTypeEthereumClassic)
        .value("fio", NWCoinType::NWCoinTypeFIO)
        .value("goChain", NWCoinType::NWCoinTypeGoChain)
        .value("groestlcoin", NWCoinType::NWCoinTypeGroestlcoin)
        .value("icon", NWCoinType::NWCoinTypeICON)
        .value("ioTeX", NWCoinType::NWCoinTypeIoTeX)
        .value("kava", NWCoinType::NWCoinTypeKava)
        .value("kin", NWCoinType::NWCoinTypeKin)
        .value("litecoin", NWCoinType::NWCoinTypeLitecoin)
        .value("monacoin", NWCoinType::NWCoinTypeMonacoin)
        .value("nebulas", NWCoinType::NWCoinTypeNebulas)
        .value("nuls", NWCoinType::NWCoinTypeNULS)
        .value("nano", NWCoinType::NWCoinTypeNano)
        .value("near", NWCoinType::NWCoinTypeNEAR)
        .value("nimiq", NWCoinType::NWCoinTypeNimiq)
        .value("ontology", NWCoinType::NWCoinTypeOntology)
        .value("poaneNWork", NWCoinType::NWCoinTypePOANeNWork)
        .value("qtum", NWCoinType::NWCoinTypeQtum)
        .value("xrp", NWCoinType::NWCoinTypeXRP)
        .value("solana", NWCoinType::NWCoinTypeSolana)
        .value("stellar", NWCoinType::NWCoinTypeStellar)
        .value("tezos", NWCoinType::NWCoinTypeTezos)
        .value("theta", NWCoinType::NWCoinTypeTheta)
        .value("thunderToken", NWCoinType::NWCoinTypeThunderToken)
        .value("neo", NWCoinType::NWCoinTypeNEO)
        .value("tomoChain", NWCoinType::NWCoinTypeTomoChain)
        .value("tron", NWCoinType::NWCoinTypeTron)
        .value("veChain", NWCoinType::NWCoinTypeVeChain)
        .value("viacoin", NWCoinType::NWCoinTypeViacoin)
        .value("wanchain", NWCoinType::NWCoinTypeWanchain)
        .value("zcash", NWCoinType::NWCoinTypeZcash)
        .value("firo", NWCoinType::NWCoinTypeFiro)
        .value("zilliqa", NWCoinType::NWCoinTypeZilliqa)
        .value("zelcash", NWCoinType::NWCoinTypeZelcash)
        .value("ravencoin", NWCoinType::NWCoinTypeRavencoin)
        .value("waves", NWCoinType::NWCoinTypeWaves)
        .value("terra", NWCoinType::NWCoinTypeTerra)
        .value("terraV2", NWCoinType::NWCoinTypeTerraV2)
        .value("harmony", NWCoinType::NWCoinTypeHarmony)
        .value("algorand", NWCoinType::NWCoinTypeAlgorand)
        .value("kusama", NWCoinType::NWCoinTypeKusama)
        .value("polkadot", NWCoinType::NWCoinTypePolkadot)
        .value("filecoin", NWCoinType::NWCoinTypeFilecoin)
        .value("elrond", NWCoinType::NWCoinTypeElrond)
        .value("bandChain", NWCoinType::NWCoinTypeBandChain)
        .value("smartChainLegacy", NWCoinType::NWCoinTypeSmartChainLegacy)
        .value("smartChain", NWCoinType::NWCoinTypeSmartChain)
        .value("oasis", NWCoinType::NWCoinTypeOasis)
        .value("polygon", NWCoinType::NWCoinTypePolygon)
        .value("thorchain", NWCoinType::NWCoinTypeTHORChain)
        .value("bluzelle", NWCoinType::NWCoinTypeBluzelle)
        .value("optimism", NWCoinType::NWCoinTypeOptimism)
        .value("arbitrum", NWCoinType::NWCoinTypeArbitrum)
        .value("ecochain", NWCoinType::NWCoinTypeECOChain)
        .value("avalancheCChain", NWCoinType::NWCoinTypeAvalancheCChain)
        .value("xdai", NWCoinType::NWCoinTypeXDai)
        .value("fantom", NWCoinType::NWCoinTypeFantom)
        .value("cryptoOrg", NWCoinType::NWCoinTypeCryptoOrg)
        .value("celo", NWCoinType::NWCoinTypeCelo)
        .value("ronin", NWCoinType::NWCoinTypeRonin)
        .value("osmosis", NWCoinType::NWCoinTypeOsmosis)
        .value("ecash", NWCoinType::NWCoinTypeECash)
        .value("cronosChain", NWCoinType::NWCoinTypeCronosChain)
        .value("smartBitcoinCash", NWCoinType::NWCoinTypeSmartBitcoinCash)
        .value("kuCoinCommunityChain", NWCoinType::NWCoinTypeKuCoinCommunityChain)
        .value("boba", NWCoinType::NWCoinTypeBoba)
        .value("metis", NWCoinType::NWCoinTypeMetis)
        .value("aurora", NWCoinType::NWCoinTypeAurora)
        .value("evmos", NWCoinType::NWCoinTypeEvmos)
        .value("nativeEvmos", NWCoinType::NWCoinTypeNativeEvmos)
        .value("moonriver", NWCoinType::NWCoinTypeMoonriver)
        .value("moonbeam", NWCoinType::NWCoinTypeMoonbeam)
        .value("kavaEvm", NWCoinType::NWCoinTypeKavaEvm)
        .value("klaytn", NWCoinType::NWCoinTypeKlaytn)
        .value("meter", NWCoinType::NWCoinTypeMeter)
        .value("okxchain", NWCoinType::NWCoinTypeOKXChain)
    ;
}

} // namespace NW::Wasm
