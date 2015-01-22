class Uhttpxx < Formula
  homepage "http://www.cybergarage.org/do/view/Main/HttpEngineForCC"
  url "https://github.com/cybergarage/uHTTP4CC/archive/0.8.tar.gz"
  sha1 "b1ceb9f266d8465c1700be0a557efc7a5495786c"

  depends_on "autoconf" => :build
  depends_on "automake" => :build
  depends_on "readline"

  def install
    system "./bootstrap"
    system "./configure_macosx", "--disable-debug",
                                 "--disable-dependency-tracking",
                                 "--disable-silent-rules",
                                 "--prefix=#{prefix}"
    system "make"
    system "make", "install"
  end
end
