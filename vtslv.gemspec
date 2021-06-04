# frozen_string_literal: true

Gem::Specification.new do |spec|
  spec.name          = "vtslv"
  spec.version       = "1.0.0"
  spec.authors       = ["Gabrielius Visockas"]
  spec.summary       = "Ruby implementation of Boost for calculating area of intersecting polygons"

  spec.required_ruby_version = Gem::Requirement.new(">= 2.3.0")
  spec.files = Dir.chdir(File.expand_path(__dir__)) do
    `find .`.split("\n").reject{_1.match(/\.gem$/)}
  end
  spec.require_paths = ["lib"]
  spec.extensions = %w[ext/vtslv/extconf.rb]
end
