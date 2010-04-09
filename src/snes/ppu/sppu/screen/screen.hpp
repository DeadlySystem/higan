class Screen {
public:
  sPPU &self;
  uint16 *output;
  uint16 *fade;

  struct {
    bool addsub_mode;
    bool direct_color;

    bool color_mode;
    bool color_halve;
    bool bg1_color_enable;
    bool bg2_color_enable;
    bool bg3_color_enable;
    bool bg4_color_enable;
    bool oam_color_enable;
    bool back_color_enable;

    uint8 color_b;
    uint8 color_g;
    uint8 color_r;
  } regs;

  void scanline();
  void run();
  void reset();

  Screen(sPPU &self);

private:
  uint16 light_table[16][32768];
  uint16 get_pixel(bool swap);
  uint16 addsub(unsigned x, unsigned y, bool halve);
  uint16 get_color(uint8 n);
  uint16 get_direct_color(unsigned n);
};