# Automatically generated by scripts/boost/generate-ports.ps1

vcpkg_from_github(
    OUT_SOURCE_PATH SOURCE_PATH
    REPO boostorg/graph
    REF boost-${VERSION}
    SHA512 fcd2554e467f499352b3ae9166891c58e49edd60a56a79197e8adf5d0c188d12df143d89667aa27d78307548ef9c30d0cce3ecf5f39404ed610283c4f3f6a4cb
    HEAD_REF master
)

set(FEATURE_OPTIONS "")
boost_configure_and_install(
    SOURCE_PATH "${SOURCE_PATH}"
    OPTIONS ${FEATURE_OPTIONS}
)