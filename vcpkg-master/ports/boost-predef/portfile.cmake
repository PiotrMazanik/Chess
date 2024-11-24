# Automatically generated by scripts/boost/generate-ports.ps1

vcpkg_from_github(
    OUT_SOURCE_PATH SOURCE_PATH
    REPO boostorg/predef
    REF boost-${VERSION}
    SHA512 b908034a88b91c1a35e2933207a09e06862994ee36f5c62d2e58842bbb4d2bcfe10069350bfb330276f6b4e1e0ff213a4f2f7b7f0ac54c12e022c6c397b32ef0
    HEAD_REF master
)

set(FEATURE_OPTIONS "")
boost_configure_and_install(
    SOURCE_PATH "${SOURCE_PATH}"
    OPTIONS ${FEATURE_OPTIONS}
)

file(COPY "${SOURCE_PATH}/libs/predef/tools/check" DESTINATION "${CURRENT_PACKAGES_DIR}/share/boost-predef")