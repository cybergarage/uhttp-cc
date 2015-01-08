class Uhttpxx < Formula
  homepage "http://www.cybergarage.org/do/view/Main/HttpEngineForCC"
  url "https://github.com/cybergarage/uHTTP4CC/archive/0.7.1.tar.gz"
  sha1 "5f1b2513e55b97c2fd06ece3a3ac1f7978af413a"

  depends_on "readline"

  def install
    system "./configure", "--disable-debug",
                          "--disable-dependency-tracking",
                          "--disable-silent-rules",
                          "--prefix=#{prefix}"
    system "make", "install"
  end
end
