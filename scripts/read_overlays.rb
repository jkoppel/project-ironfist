
#WARNING: This uses eval to parse strings

LOCATION_TYPES = {
  1 => "LOCATION_ALCHEMIST_LAB",
  2 => "LOCATION_SIGN",
  3 => "LOCATION_BUOY",
  4 => "LOCATION_SKELETON",
  5 => "LOCATION_DAEMON_CAVE",
  6 => "LOCATION_TREASURE_CHEST",
  7 => "LOCATION_FAERIE_RING",
  8 => "LOCATION_CAMPFIRE",
  9 => "LOCATION_FOUNTAIN",
  10 => "LOCATION_GAZEBO",
  11 => "LOCATION_ANCIENT_LAMP",
  12 => "LOCATION_GRAVEYARD",
  13 => "LOCATION_ARCHERS_HOUSE",
  14 => "LOCATION_GOBLIN_HUT",
  15 => "LOCATION_DWARF_COTTAGE",
  16 => "LOCATION_PEASANT_HUT",
  17 => "LOCATION_LOG_CABIN",
  18 => "LOCATION_ROAD",
  19 => "LOCATION_EVENT",
  20 => "LOCATION_DRAGON_CITY",
  21 => "LOCATION_LIGHTHOUSE",
  22 => "LOCATION_WATERWHEEL",
  23 => "LOCATION_MINE",
  24 => "LOCATION_ARMY_CAMP",
  25 => "LOCATION_OBELISK",
  26 => "LOCATION_OASIS",
  27 => "LOCATION_RESOURCE",
  29 => "LOCATION_SAWMILL",
  30 => "LOCATION_ORACLE",
  31 => "LOCATION_SHRINE_FIRST",
  32 => "LOCATION_SHIPWRECK",
  33 => "LOCATION_SEA_CHEST",
  34 => "LOCATION_DESRT_TENT",
  35 => "LOCATION_TOWN",
  36 => "LOCATION_STONE_LITHS",
  37 => "LOCATION_WAGON_CAMP",
  38 => "LOCATION_WELL",
  39 => "LOCATION_WHIRLPOOL",
  40 => "LOCATION_WINDMILL",
  41 => "LOCATION_ARTIFACT",
  42 => "LOCATION_HERO",
  43 => "LOCATION_BOAT",
  45 => "LOCATION_RANDOM_ARTIFACT",
  46 => "LOCATION_RANDOM_RESOURCE",
  47 => "LOCATION_RANDOM_MONSTER",
  48 => "LOCATION_RANDOM_TOWN",
  49 => "LOCATION_RANDOM_CASTLE",
  51 => "LOCATION_RANDOM_MONSTER_WEAK",
  52 => "LOCATION_RANDOM_MONSTER_MEDIUM",
  53 => "LOCATION_RANDOM_MONSTER_STRONG",
  54 => "LOCATION_RANDOM_MONSTER_VERY_STRONG",
  55 => "LOCATION_RANDOM_HERO",
  56 => "LOCATION_NOTHING_SPECIAL",
  58 => "LOCATION_WATCH_TOWER",
  59 => "LOCATION_TREE_HOUSE",
  60 => "LOCATION_TREE_CITY",
  61 => "LOCATION_RUINS",
  62 => "LOCATION_FORT",
  63 => "LOCATION_TRADING_POST",
  64 => "LOCATION_ABANDONED_MINE",
  65 => "LOCATION_DWARF_CABIN",
  66 => "LOCATION_STANDING_STONES",
  67 => "LOCATION_IDOL",
  68 => "LOCATION_TREE_OF_KNOWLEDGE",
  69 => "LOCATION_WITCH_DOCTORS_HUT",
  70 => "LOCATION_TEMPLE",
  71 => "LOCATION_HILL_FORT",
  72 => "LOCATION_HALFLING_HOLE",
  73 => "LOCATION_MERCENARY_CAMP",
  74 => "LOCATION_SHRINE_SECOND_ORDER",
  75 => "LOCATION_SHRINE_THIRD_ORDER",
  76 => "LOCATION_PYRAMID",
  77 => "LOCATION_CITY_OF_DEAD",
  78 => "LOCATION_EXCAVATION",
  79 => "LOCATION_SPHINX",
  80 => "LOCATION_WAGON",
  81 => "LOCATION_TAR_PIT",
  82 => "LOCATION_ARTESIAN_SPRING",
  83 => "LOCATION_TROLL_BRIDGE",
  84 => "LOCATION_WATERING_HOLE",
  85 => "LOCATION_WITCH_HUT",
  86 => "LOCATION_XANADU",
  87 => "LOCATION_CAVE",
  88 => "LOCATION_LEAN_TO",
  89 => "LOCATION_MAGELLANS_MAPS",
  90 => "LOCATION_FLOTSAM",
  91 => "LOCATION_DERELICT_SHIP",
  92 => "LOCATION_SHIPWRECK_SURVIVOR",
  93 => "LOCATION_BOTTLE",
  94 => "LOCATION_MAGIC_WELL",
  95 => "LOCATION_MAGIC_GARDEN",
  96 => "LOCATION_OBSERVATION_TOWER",
  97 => "LOCATION_FREEMANS_FOUNDRY",
  98 => "LOCATION_STREAM",
  99 => "LOCATION_TREES",
  100 => "LOCATION_MOUNTAINS",
  101 => "LOCATION_VOLCANO",
  102 => "LOCATION_FLOWERS",
  103 => "LOCATION_ROCK",
  104 => "LOCATION_LAKE",
  105 => "LOCATION_MANDRAKE",
  106 => "LOCATION_DEAD_TREE",
  107 => "LOCATION_STUMP",
  108 => "LOCATION_CRATER",
  109 => "LOCATION_CACTUS",
  110 => "LOCATION_MOUND",
  111 => "LOCATION_DUNE",
  112 => "LOCATION_LAVA_POOL",
  113 => "LOCATION_SHRUB",
  114 => "LOCATION_HOLE",
  115 => "LOCATION_OUTCROPPING",
  116 => "LOCATION_RANDOM_ARTIFACT_TREASURE",
  117 => "LOCATION_RANDOM_ARTIFACT_MINOR",
  118 => "LOCATION_RANDOM_ARTIFACT_MAJOR",
  119 => "LOCATION_BARRIER",
  120 => "LOCATION_TRAVELLER_TENT",
  121 => "LOCATION_EXPANSION_DWELLING",
  122 => "LOCATION_ALCHEMIST_TOWER",
  123 => "LOCATION_JAIL"
}

TILESETS = {
  10 => "TILESET_HAUNTED",
  11 => "TILESET_ARTIFACT",
  12 => "TILESET_MONSTER",
  13 => "TILESET_ARTIFACT_TAKEN",
  14 => "TILESET_FLAG",
  15 => "TILESET_RESOURCE_DISPLAY",
  16 => "TILESET_HOURGLASS",
  17 => "TILESET_ROUTE",
  19 => "TILESET_STONBACK",
  20 => "TILESET_MONSTER_ANIMATION",
  21 => "TILESET_HERO",
  22 => "TILESET_SNOW_MOUNTAIN",
  23 => "TILESET_SWAMP_MOUNTAIN",
  24 => "TILESET_LAVA_MOUNTAIN",
  25 => "TILESET_DESERT_MOUNTAIN",
  26 => "TILESET_DIRT_MOUNTAIN",
  27 => "TILESET_MOUNTAIN_MULTIPLE",
  29 => "TILESET_EXTRA_OVERLAY",
  30 => "TILESET_ROAD",
  31 => "TILESET_MOUNTAIN_CRACKED",
  32 => "TILESET_MOUNTAIN_GRASS",
  33 => "TILESET_TREE_JUNGLE",
  34 => "TILESET_TREE_EVIL",
  35 => "TILESET_OBJ_TOWN",
  36 => "TILESET_TOWN_TERRAIN",
  37 => "TILESET_TOWN_SHADOW",
  38 => "TILESET_TOWN_RANDOM",
  39 => "TILESET_OBJECT_EXTRA",
  40 => "TILESET_OBJECT_WATER_2",
  41 => "TILESET_OBJECT_MULTIPLE_2",
  42 => "TILESET_OBJECT_TREE_SNOW",
  43 => "TILESET_OBJECT_TREE_FIR",
  44 => "TILESET_OBJECT_TREE_FALL",
  45 => "TILESET_OBJECT_STREAM",
  46 => "TILESET_OBJECT_RESOURCE",
  47 => "TILESET_OBJECT_DUMMY",
  48 => "TILESET_OBJECT_GRASS_2",
  49 => "TILESET_OBJECT_TREE_DECIDUOUS",
  50 => "TILESET_OBJECT_WATER",
  51 => "TILESET_OBJECT_GRASS",
  52 => "TILESET_OBJECT_SNOW",
  53 => "TILESET_OBJECT_SWAMP",
  54 => "TILESET_OBJECT_LAVA",
  55 => "TILESET_OBJECT_DESERT",
  56 => "TILESET_OBJECT_DIRT",
  57 => "TILESET_OBJECT_CRACKED",
  58 => "TILESET_OBJECT_LAVA_3",
  59 => "TILESET_OBJECT_MULTIPLE",
  60 => "TILESET_OBJECT_LAVA_2",
  61 => "TILESET_OBJECT_EXPANSION_1",
  62 => "TILESET_OBJECT_EXPANSION_2",
  63 => "TILESET_OBJECT_EXPANSION_3",
}

OVERLAY_CATEGORIES = {
  0 => "CATEGORY_TERRAIN",
  1 => "CATEGORY_TREASURE",
  2 => "CATEGORY_CREATURE",
  3 => "CATEGORY_ARTIFACT",
  5 => "CATEGORY_TOWN",
  6 => "CATEGORY_BUILTIN",
  7 => "CATEGORY_HERO"
}

TERRAIN_TYPES = {
  0 => "TERRAIN_WATER",
  1 => "TERRAIN_GRASS",
  2 => "TERRAIN_SNOW",
  3 => "TERRAIN_SWAMP",
  4 => "TERRAIN_LAVA",
  5 => "TERRAIN_DESERT",
  6 => "TERRAIN_DIRT",
  7 => "TERRAIN_WASTELAND",
  8 => "TERRAIN_SAND"
}

#TODO: Check
PLAYER_COLORS = {
  0 => "PLAYER_BLUE",
  1 => "PLAYER_GREEN",
  2 => "PLAYER_YELLOW",
  3 => "PLAYER_RED",
  4 => "PLAYER_ORANGE",
  5 => "PLAYER_PURPLE"
}

def assert(b, msg="Assertion failure")
  if not b then
    puts msg
    exit 1
  end
end


def read_i64(str)
  md = str.match(/^(\d+)i64$/)
  assert(md != nil)
  md[1].to_i
end  


def read_char(str)
  eval(str.gsub("'", "\"")).getbyte(0)
end

def read_str(str)
  eval(str)
end

def flipMask(x)
  (x >> 32) | ((x & 0xFFFFFFFF) << 32)
end


def displayMask(mask_raw)
  str = ""
  sep = ""
  mask = flipMask(mask_raw)
  0.upto(5) do |y|
    str << sep
    sep = "\n"
    0.upto(7) do |x|
      i = (7 - x) + 8 * (5 - y)
      str << (((1 << i) & mask) == 0 ? "0" : "1")
    end
  end

  str
end

def intToSet(mask)
  set = {}
  i = 0
  while mask != 0
    if (mask & 1) != 0
      set[i] = true
    end

    mask >>= 1
    i += 1
  end

  set
end

INDENTATION = 4
def indent(n, str)
  str.gsub(/^/, " " * n)
end

class Tag
  def initialize(name)
    @name = name
    @attrs = []
    @elts = []
    @body = nil
  end

  def attr(key, val)
    @attrs << [key.to_s, val.to_s]
    self
  end

  def element(t)
    @elts << t
    self
  end

  def body(t)
    @body = t
    self
  end

  def to_s
    res = "<#{@name}" + @attrs.map{|(key, val)| " " + key + '="' + val + '"'}.join
    if @body == nil
      res << "/>"
    else
      res << ">\n" << indent(INDENTATION, @body.to_s) << "\n" << "</#{@name}>"
    end
    res
  end
end

class TagSeq
  def initialize
    @tags = []
  end

  def append(t)
    @tags << t
    self
  end

  def appendAll(ts)
    ts.each {|t| self.append(t) }
    self
  end

  def to_s
    @tags.map{|x| x.to_s}.join("\n")
  end

  def TagSeq.fromArr(tags)
    tags.inject(TagSeq.new) {|s, t| s.append(t) }
  end
end
# 185 tokens
# arr.map {|x| f(x) } is 12 tokens


#FIXME: What do 9, 10, 11 mean?
def terrainMaskToTags(mask)
  intToSet(mask).keys.map {|t| Tag.new("validTerrain").body(TERRAIN_TYPES[t]) }
end

#Notes on overlay
# Indices are important; lots of places where hardcoded indices are accessed
# idx2 is usually = to idx1, but there are many exceptions
# Same for ordinal, but with more exceptions
# fullGridIconIndices is computed at runtime
# sub_42EC3D touches field_E
# field_4D is written at runtime; appears to be never touched
# field_4B is maybe something like "hasShadow"; it's checked a lot in PlaceOverlay. It's always 0 or 1
# field_4E is either 0, 1111, or 9999
# field_42 is accessed in drawOverlay
# I did a pretty full trace through the code to find every touch of overlay. It appears that field_10 is never accessed
#
# field_4D is always 8
#
# The displayMask method above interprets the bitmasks. Exception: terrain masks
# When ordinal is non-increasing, it means something interesting (see PopulateAvailOverlays)

class Overlay
  attr_accessor :idx, :idx2, :ordinal, :tileset, :category, :field_E, :animationLength, :intersectsTileMask
  attr_accessor :terrainObjCategoryMask, :allowedTerrainPlacementMask, :coveredNonObstructedMask
  attr_accessor :shadowsMask, :animatedLateOverlay, :resourceField, :townColorOrMineColor
  attr_accessor :field_42, :interactionPointMask, :field_4B, :locationType, :field_4D, :field_4E
  attr_accessor :fullGridIconIndices

  def display_nice
    str = <<-START
      Idx: #{self.idx}
      Tileset: #{TILESETS[self.tileset]}
      Category: #{OVERLAY_CATEGORIES[self.category]}
      Color: #{self.townColorOrMineColor}
      field_4E: #{self.field_4E}
      Intersects:
#{displayMask(self.intersectsTileMask)}

      Animation Length: #{self.animationLength}
      Animated tiles:
#{displayMask(self.animatedLateOverlay)}

    START
    str
  end

  def to_xml
    Tag.new("overlay")
      .attr("idx", @idx)
      .attr("idx2", @idx2)
      .attr("ordinal", @ordinal)
      .attr("tileset", TILESETS[@tileset])
      .attr("category", OVERLAY_CATEGORIES[@category])
      .attr("animationLength", @animationLength)
      .attr("color", PLAYER_COLORS[@townColorOrMineColor])
      .body(TagSeq.new
              .append(Tag.new("tiles").body(displayMask(@intersectsTileMask)))
              .append(Tag.new("animatedTiles").body(displayMask(@animatedLateOverlay)))
              .append(Tag.new("coveredNonObstructed").body(displayMask(@coveredNonObstructedMask)))
              .append(Tag.new("shadows").body(displayMask(@shadowsMask)))
              .appendAll(terrainMaskToTags(@allowedTerrainPlacementMask)))
  end
end  

def parse_overlay(str)
  fields = str.split(",").map {|x| x.strip }
  assert(fields.size == 22, "Parsed overlay as having wrong number of fields: " + str)

  overlay = Overlay.new

  overlay.idx = fields[0].to_i # check
  overlay.idx2 = fields[1].to_i # check
  overlay.ordinal = fields[2].to_i # check
  overlay.tileset = fields[3].to_i # check (but enums off?)
  overlay.category = fields[4].to_i # check (but enums off)
  overlay.field_E = fields[5].to_i
  overlay.animationLength = read_char(fields[6]) # check
  overlay.intersectsTileMask = read_i64(fields[7]) # check
  overlay.terrainObjCategoryMask = fields[8].to_i
  overlay.allowedTerrainPlacementMask = fields[9].to_i # check
  overlay.coveredNonObstructedMask = read_i64(fields[10]) # check
  overlay.shadowsMask = read_i64(fields[11]) # check
  overlay.animatedLateOverlay = read_i64(fields[12]) # check
  overlay.resourceField = read_i64(fields[13])
  overlay.townColorOrMineColor = read_char(fields[14]) # check
  overlay.field_42 = read_char(fields[15])
  overlay.interactionPointMask = read_i64(fields[16])
  overlay.field_4B = read_char(fields[17])
  overlay.locationType = fields[18].to_i
  overlay.field_4D = read_char(fields[19])
  overlay.field_4E = fields[20].to_i
  overlay.fullGridIconIndices = read_str(fields[21])
  
  overlay
end

def read_overlays(fil)
  contents = File.open(fil) {|f| f.readlines.join("\n") }
  overlay_defs = contents.split(/},\s+{/).map {|x| x.strip }
  overlay_defs.map {|x| parse_overlay(x) }
end

def overlays_to_xml(overlays)
  TagSeq.new
    .append('<?xml version="1.0"?>')
    .append(Tag.new("overlays")
              .attr("xmlns:xsi", "http://www.w3.org/2001/XMLSchema-instance")
              .attr("xsi:noNamespaceSchemaLocation", "overlays_xml.xsd")
              .body(TagSeq.fromArr(overlays.map {|x| x.to_xml})))
end

if __FILE__ == $0
  ovr = read_overlays(ARGV[0])
  puts overlays_to_xml(ovr).to_s
end
