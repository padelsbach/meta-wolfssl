# OpenSSL standalone wolfProvider mode configuration
# Include this file for standard wolfProvider integration as a provider plugin

EXTRA_OECONF += " no-fips shared "

do_install:append() {
    install -d ${D}${sysconfdir}/openssl
    echo "0" > ${D}${sysconfdir}/openssl/replace-default-enabled
}

# Disable internal keymgmt tests under wolfprovider FIPS mode which
# fails on the FACTOR3 and EXPONENT3 and COEFFICIENT2 parameters which
# are not supported by wolfProvider.
SRC_URI:append:class-target = " file://openssl-disable-internal-keymgmt-tests.patch"


